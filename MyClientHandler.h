//
// Created by zohar on 08/02/2020.
//

#ifndef FLIGHTSIM2ND_MYCLIENTHANDLER_H
#define FLIGHTSIM2ND_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
using namespace server_side;
class MyClientHandler: public server_side::ClientHandler {
    //a client handler is comprised of a solver and a CacheManager
    Solver<vector<vector<double>>, string> *solver;
    CacheManager *cm;

public:
    void handleClient(int socket) override;

    MyClientHandler(Solver<vector<vector<double>>, string> *sol, CacheManager *cman){
        this->solver=sol;
        this->cm=cman;
    }

    vector<double> getRow(string row);
};


#endif //FLIGHTSIM2ND_MYCLIENTHANDLER_H
