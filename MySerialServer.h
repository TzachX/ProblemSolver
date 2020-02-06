//
// Created by ardeus on 30/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H


#include "Server.h"

namespace server_side {
    class MySerialServer : public Server {
    public:
        MySerialServer();

        ~MySerialServer();

        void open(int port, ClientHandler *c);

        void stop();
        // zohar part
    };
}

#endif //EX4_MYSERIALSERVER_H
