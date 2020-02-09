//
// Created by ardeus on 30/01/2020.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include "MySerialServer.h"

using namespace server_side;

/***
 * accpet users in serial
 * @param port given port
 * @param c clienthandler
 */
void server_side::MySerialServer::open(int port, ClientHandler *c) {

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        cout << "socket error";
    }

    sockaddr_in adress;
    bzero((char *) &adress, sizeof(adress));
    adress.sin_family = AF_INET;
    adress.sin_addr.s_addr = INADDR_ANY;
    adress.sin_port = htons(port);
    int binding = bind(socketfd, (struct sockaddr *) &adress, sizeof(adress));

    if (binding == -1) {
        //could not bind socket to IP
        cout << "bind error";

        return;
    }

    if (listen(socketfd, 1) == -1) {
        cout << "listen error";
        return;
    }

    while (!shouldStop) {
        //accpets users in serial, operates whilst not stoppes (and connections had been made)
        timeval sleep;
        sleep.tv_sec = 10;
        sleep.tv_usec = 0;
        setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &sleep, sizeof(sleep));
        int client = accept(socketfd, (struct sockaddr *) &adress, (socklen_t *) &adress);
        this->sock = client;
        if (client == -1) {

            if (shouldStop) {
                break;
            }
            if (errno == EWOULDBLOCK) {
                continue;
            } else {
                throw invalid_argument("accept error");
            }
        } else {
            c->handleClient(client);
        }


    }

}
/***
 * stops the server
 */
void server_side::MySerialServer::stop() {

    shouldStop = true;
    close(this->sock);
}
