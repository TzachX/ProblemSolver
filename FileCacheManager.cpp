//
// Created by ardeus on 01/02/2020.
//

#include <fstream>
#include "FileCacheManager.h"

/***
 * searches a solution in the cache and file system
 * @param p problem
 * @return if the solution was found
 */
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
/***
 * stores a solution and a problem, as pair, in the cache and filesystem
 * @param p problem
 * @param s solution
 */
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


/***
 * returns a solution to a given problem
 * @param p - given problem
 * @return solution to said problem
 */
string server_side::FileCacheManager::getSolution(string p)
{
    // Check if solution exists
    if (isSolutionFound(p))
        // Return the solution
        return solutionMap[p];

    // Throw error in case it wasn't found
    throw invalid_argument("The solution to this problem doesn't exist in the stack");
}

/***
 * creates a file cache manager using a solution file (if exists)
 * @param name - file name for the solution
 */
server_side::FileCacheManager::FileCacheManager(string name)
{
    string problem, solution;
    string temp;
    bool isSol=false;
    fileName = name;
    ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        while (getline(inputFile, temp))
        //disassembly of the matrix inside said file
        {
            if(!isSol) {
                if (temp == "end") {
                    problem += "end";
                    isSol=true;
                }
                problem+=temp;
                problem+="\n";

            }
            else {
                solution += temp;

            }
        }
        //assigning the problem to it's solution
        solutionMap[problem] = solution;
        inputFile.close();
    }

}




