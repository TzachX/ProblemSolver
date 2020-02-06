//
// Created by ardeus on 01/02/2020.
//

#include <fstream>
#include "FileCacheManager.h"

bool server_side::FileCacheManager::isSolutionFound(string p)
{
    // Locking the thread to search for solution without interferences
    pthread_mutex_lock(&mutex);

    // Saving the iterator in the desired place
    unordered_map<string, string>::iterator it = solutionMap.find(p);

    // Unlocking the thread for other usages
    pthread_mutex_unlock(&mutex);

    // Return if solution found
    return it != solutionMap.end();
}

void server_side::FileCacheManager::storeSolution(string p, string s) {
    // Locking the thread to store the solution without interferences
    pthread_mutex_lock(&mutex);

    // Saving the solution value in the 'problem' index
    solutionMap[p] = s;

    // Define the data file object and opening it in appending mode
    ofstream dataFile;
    dataFile.open(fileName, std::ios::app);

    /*
     * If file opened successfully, write the data like this:
     * PROBLEM
     * SOLUTION
    */
    if (dataFile.is_open())
    {
        dataFile << p + "\n" + s + "\n";
    }
    else
    {
        throw invalid_argument("Error while trying to open file");
    }

    // Close the file
    dataFile.close();

    // Unlock the thread
    pthread_mutex_unlock(&mutex);
}

string server_side::FileCacheManager::getSolution(string p)
{
    // Check if solution exists
    if (isSolutionFound(p))
        // Return the solution
        return solutionMap[p];

    // Throw error in case it wasn't found
    throw invalid_argument("The solution to this problem doesn't exist in the stack");
}

server_side::FileCacheManager::FileCacheManager(string name)
{
    string problem, solution;
    fileName = name;
    ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        while (getline(inputFile, problem))
        {
            if (getline(inputFile, solution))
                solutionMap[problem] = solution;
            else
                throw invalid_argument("Error in file format");
        }
        inputFile.close();
    }
}




