//
// Created by zohar on 08/02/2020.
//

#include <netinet/in.h>
#include <unistd.h>
#include "MyParallelServer.h"



/***
 * opens a socket or sockets and accept multiple clients
 * @param port - given port
 * @param c - given client handler
 */
void MyParallelServer::open(int port, ClientHandler *c) {
    vector<pthread_t> threadsVector;
    int count=0;
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);

    if (socketfd == -1) {
        //error
        cout << "socket error\n";
        return;
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    int binding = bind(socketfd, (struct sockaddr *) &address, sizeof(address));
    if (binding == -1) {
        //error
        cout << "bind error\n";
        return;
    }


    if (listen(socketfd, SOMAXCONN) == -1) {
        cout << "listen error\n";
    }
    this->sock=socketfd;
    while (!shouldStop) {


        int client = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
        cout<<"client is"+ client;

        if (client == -1) {
            if (shouldStop) {
                break;
            }
            if (errno == EWOULDBLOCK) {
                continue;
            } else {
                close(socketfd);
                throw invalid_argument("accept error\n");
            }
        } else {
            //wraps the information for the client handler
            //this is done due to limits within the pthread_t class in cpp
            thrData* passData;
            passData=new thrData;
            passData->socket =client;
            passData->c=c;
            pthread_t parThread;
            pthread_create(&parThread, nullptr, parHandleThread,passData);
            threadsVector.push_back(parThread);
            timeval sleep;
            sleep.tv_sec = 1;
            sleep.tv_usec = 0;
            setsockopt(port, SOL_SOCKET, SO_RCVTIMEO, (char *) &sleep, sizeof(sleep));
        }


    }
    for (int i = 0; i < threadsVector.size(); i++) {


        pthread_join(threadsVector[i], nullptr);
        cout<<"thread join\n";
    }


}
/***
 * stops the server's connection
 */
void MyParallelServer::stop() {
    shouldStop=true;
    close(this->sock);
}

/***
 * wrapper to handle pthread within a class
 * @param data - data for client handler
 * @return nullptr
 */
void* MyParallelServer::parHandleThread(void* data) {
    thrData* pass = (thrData*)data;
    pass->c->handleClient(pass->socket);
    delete(pass);
    return nullptr;


}
