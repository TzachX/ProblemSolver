//
// Created by zohar on 08/02/2020.
//

#ifndef FLIGHTSIM2ND_MYPARALLELSERVER_H
#define FLIGHTSIM2ND_MYPARALLELSERVER_H

#include <thread>
#include "Server.h"
#include <vector>
using namespace std;
using namespace server_side;

class MyParallelServer: public Server {

    bool shouldStop=false;
    int sock;

public:
    void open(int port, ClientHandler *c) override;

    void stop() override;

   static void* parHandleThread(void* data);

    struct thrData{
        int socket;
        ClientHandler* c;
    };

};


#endif //FLIGHTSIM2ND_MYPARALLELSERVER_H