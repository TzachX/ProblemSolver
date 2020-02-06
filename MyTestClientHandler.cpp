//
// Created by ardeus on 30/01/2020.
//

#include "MyTestClientHandler.h"

void server_side::MyTestClientHandler::handleClient(istream input, ostream output)
{
    for (string currString; getline(input, currString);)
    {
        if (cm->isSolutionFound(currString))
            output << currString;
        else
        {
            string solution = solver->solve(currString);
            cm->storeSolution(currString, solution);
            output << solution;
        }
    }
}

server_side::MyTestClientHandler::MyTestClientHandler(server_side::Solver<string, string> *solver,
                                                      server_side::CacheManager *cm) : solver(solver), cm(cm) {}
