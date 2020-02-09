//
// Created by ardeus on 30/01/2020.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

namespace server_side
{
    class MyTestClientHandler : public ClientHandler
    {
    private:
        Solver<string, string> *solver;
        CacheManager *cm;
    public:
        void handleClient(int socket);

        MyTestClientHandler();

       MyTestClientHandler(Solver<string, string> *solver, CacheManager *cm) : solver(solver), cm(cm) {}


        ~MyTestClientHandler(){
            delete(solver);
            delete(cm);
        }
    };
}


#endif //EX4_MYTESTCLIENTHANDLER_H
