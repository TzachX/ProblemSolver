//
// Created by ardeus on 30/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H


#include <thread>
#include <vector>
#include "Server.h"
using namespace std;
namespace server_side {
    class MySerialServer : public Server {
        //holds a run boolean and a socket
        bool shouldStop = false;
        int sock;

    public:
        MySerialServer();

        ~MySerialServer();

        void open(int port, ClientHandler *c);

        void stop();
        // zohar part
    };
}

#endif //EX4_MYSERIALSERVER_H
