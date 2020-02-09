//
// Created by ardeus on 30/01/2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

#include <iostream>
using namespace std;
namespace server_side
{
    class ClientHandler {
    public:
        virtual void handleClient(int socket)=0;
        virtual ~ClientHandler(){}
    };
}

#endif //EX4_CLIENTHANDLER_H
