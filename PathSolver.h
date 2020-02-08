//
// Created by ardeus on 09/02/2020.
//

#ifndef EX4_PATHSOLVER_H
#define EX4_PATHSOLVER_H

#include <string>
#include <vector>
#include "Solver.h"
#include "Node.h"
#include "BestFirstSearcher.h"
#include "MatrixSearchable.h"

using namespace std;

namespace server_side
{
    class PathSolver : public Solver<string, vector<vector<double>>>
    {
    public:
        ~PathSolver(){}

        string solve(vector<vector<double>> table)
        {
            // Experiment results show that best first search is the best algorithm for our case, so we'll use it
            Searcher<pair<int, int>, vector<Node<pair<int, int>>*>>* searcher = new BestFirstSearcher<pair<int, int>>();
            Searchable<pair<int, int>>* searchable = new MatrixSearchable(table);
            vector<Node<pair<int, int>>*> solution = searcher->search(searchable);

            // Optimization: storing the size instead of getting it from a function every time
            int size = solution.size();

            if (size == 0)
                return "-1";

            string answerString = "";

            // Going through the solution path and printing the directions in each step
            for (int i = 0; i < size - 1; i++)
            {
                pair<int, int> currCell = solution[i]->getNodeValue();
                pair<int, int> nextCell = solution[i + 1]->getNodeValue();

                if (currCell.first > nextCell.first)
                    answerString += "Up";
                else if (currCell.first < nextCell.first)
                    answerString += "Down";
                else if (currCell.second > nextCell.second)
                    answerString += "Left";
                else if (currCell.second < nextCell.second)
                    answerString += "Right";

                delete(solution[i]);

                if (i < size - 2)
                    answerString += ",";
                else
                    delete(solution[i + 1]);
            }

            delete(searcher);
            delete(searchable);

            return answerString;
        }
    };
}


#endif //EX4_PATHSOLVER_H
