//
// Created by ardeus on 30/01/2020.
//

#include "MyTestClientHandler.h"
#include <strings.h>
#include <unistd.h>

/***
 * test client handler, see documentation in original assignment
 * @param socket
 */
void server_side::MyTestClientHandler::handleClient(int socket) {
    char buffer[1024];
    bzero(buffer, 1024);
    string prob;
    string sol = "";

    int valread;
    while (true) {
        valread = read(socket, buffer, sizeof(buffer));
        if (valread == -1) {
            cout << "read error\n";
            return;
        }
        prob = buffer;
        prob = prob.erase(prob.find('\n'));

        if (prob == "end") {
            break;
        }
        if (prob.length() < 1) {
            continue;
        }

        //checks if a problem is within the Cache
        if (cm->isSolutionFound(prob))
            sol = cm->getSolution(prob);
        else {
            //creates a solution if non existant
            sol = solver->solve(prob);
            cm->storeSolution(prob, sol);
        }

        sol+="\n";
        write(socket, sol.c_str(),sol.length());
        close(socket);
    }

}

