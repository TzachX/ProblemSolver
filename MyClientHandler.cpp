//
// Created by zohar on 08/02/2020.
//

#include <sys/socket.h>
#include <vector>
#include <unistd.h>
#include "MyClientHandler.h"

/***
 * accept a socket, and gets data from user (problem)
 * in this method we deconstruct the data to create a matrix\problem
 * @param socket - given socket
 */
void MyClientHandler::handleClient(int socket) {
    vector<vector<double>> matrixProblem;
    string lines = "";
    string prob;
    string sol;
    char buffer[1024];
    bool shouldStop = false;
    int valread;
    int count = 0;
    char curr;
    while (!shouldStop) {
        vector<double> rowMake;
        //valread will return number of bytes received
        valread = recv(socket, buffer, 1024, 0);
        if (valread == -1) {

            cout << "read error\n";
            return;

        }

        for (int i = 0; i < valread; ++i) {

            //reading information char by char
            curr = buffer[i];

            //if an "end" prompt arrived, end the operation.
            if (lines == "end") {
                prob += "end";
                shouldStop = true;
                break;
            }

            //if a new line occured, generate a line to push into the matrix
            if (curr == '\n') {
                prob += lines;
                prob += "\n";
                rowMake = getRow(lines);
                matrixProblem.push_back(rowMake);
                lines = "";
                continue;
            }
            //builds the line
            lines += curr;
            continue;

        }


    }

    //checks the CacheManager to see if the solution exists
    if (cm->isSolutionFound(prob))
        sol = cm->getSolution(prob);
    else {
        //creates a solution if non existant in the CacheManager
        sol = solver->solve(matrixProblem);
        cm->storeSolution(prob, sol);
    }

    sol += "\n";
    //returns the information to the user.
    write(socket, sol.c_str(), sol.length());
    close(socket);
}

/***
 * creates a row from string for the problem matrix
 * @param row - number row, unparsed
 * @return a row of numbers(of the matrix)
 */
vector<double> MyClientHandler::getRow(string row) {
    vector<double> splitVec;
    string token;
    string curr;
    for (int i = 0; i < row.size(); ++i) {
        curr = row[i];
        if (curr == ",") {
            if (!token.empty()) {
                splitVec.push_back(stod(token));
            }
            token = "";
            continue;
        }
        token += row[i];
    }
    if (!token.empty()) {
        splitVec.push_back(stod(token));
    }
    return splitVec;
}
