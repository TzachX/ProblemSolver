//
// Created by ardeus on 08/02/2020.
//

#include "MatrixSearchable.h"
#include <math.h>

MatrixSearchable::MatrixSearchable(const vector<vector<double>> &matrixTable)
{
    // initialize the matrix
    matrix = matrixTable;

    // initializing the init and goal Nodes
    vector<double> beginning = matrixTable[matrixTable.size() - 2];
    vector<double> goal = matrixTable[matrixTable.size() - 1];
    pair<int, int> initial = {(int) beginning[0], (int) beginning[1]};
    pair<int, int> goaler = {(int) goal[0], (int) goal[1]};

    double startCost = matrixTable[initial.first][initial.second];
    double endCost = matrixTable[goaler.first][goaler.second];

    start = new Node<pair<int, int>>(initial, startCost, nullptr);
    end = new Node<pair<int, int>>(goaler, endCost, nullptr);
}

vector<Node<pair<int, int>> *> MatrixSearchable::getPaths(Node<pair<int, int>> *node)
{
    unsigned long numOfRows = matrix.size() - 2;
    unsigned long numOfColumns = matrix[1].size();
    vector<Node<pair<int, int> >*> adj;
    int row = node->getNodeValue().first;
    int column = node->getNodeValue().second;

    // If the node is not in the last row
    if (row + 1 < numOfRows ) {
        pair<int, int> tempPair = {row + 1, column};
        double tempCost = matrix[row + 1][column] ;
        if (tempCost != -1) {

            adj.push_back(new Node<pair<int, int>>(tempPair, tempCost+ node->getCost(), node));
        }
    }

    // If the node is not in the first row
    if (row - 1 >= 0) {
        pair<int, int> tempPair = {row - 1, column};
        double tempCost = matrix[row - 1][column] ;
        if (tempCost != -1) {
            adj.push_back(new Node<pair<int, int>>(tempPair, tempCost+ node->getCost(), node));
        }
    }

    // If the node is not in the first column
    if (column - 1 >= 0) {
        pair<int, int> tempPair = {row, column - 1};
        double tempCost = matrix[row][column - 1];
        if (tempCost != -1) {

            adj.push_back(new Node<pair<int, int>>(tempPair, tempCost+ node->getCost(), node));
        }
    }

    // If the node is not in the last column
    if (column + 1 < numOfColumns) {
        pair<int, int> tempPair = {row, column + 1};
        double tempCost = matrix[row][column + 1];
        if (tempCost != -1) {
            adj.push_back(new Node<pair<int, int>>(tempPair, tempCost+ node->getCost(), node));
        }
    }

    return adj;
}

vector<Node<pair<int, int>> *> MatrixSearchable::getPaths(Node<pair<int, int>> *curr, Node<pair<int, int>> *goal) {
    unsigned long numOfRows = matrix.size() - 2;
    unsigned long numOfColumns = matrix[1].size();
    vector<Node<pair<int, int> > *> adj;
    int row = curr->getNodeValue().first;
    int column = curr->getNodeValue().second;
    int currHeuristic = abs(goal->getNodeValue().first - row) + abs(goal->getNodeValue().second - column);
    int nextHeuristic, combinedHeuristic;

    // If the node is not in the last row
    if (row + 1 < numOfRows ) {
        nextHeuristic =  abs(goal->getNodeValue().first - row + 1) + abs(goal->getNodeValue().second - column);
        combinedHeuristic = abs(nextHeuristic - currHeuristic);
        pair<int, int> tempPair = {row + 1, column};
        double tempCost = matrix[row + 1][column] ;
        if (tempCost != -1) {
            adj.push_back(new Node<pair<int, int>>(tempPair, tempCost + curr->getCost() + combinedHeuristic, curr));
        }
    }

    // If the node is not in the first row
    if (row - 1 >= 0) {
        nextHeuristic =  abs(goal->getNodeValue().first - row - 1) + abs(goal->getNodeValue().second - column);
        combinedHeuristic = abs(nextHeuristic - currHeuristic);
        pair<int, int> tempPair = {row - 1, column};
        double tempCost = matrix[row - 1][column] ;
        if (tempCost != -1) {
            adj.push_back(new Node<pair<int, int>>(tempPair, tempCost + curr->getCost() + combinedHeuristic, curr));
        }
    }

    // If the node is not in the first column
    if (column - 1 >= 0) {
        nextHeuristic =  abs(goal->getNodeValue().first - row) + abs(goal->getNodeValue().second - column - 1);
        combinedHeuristic = abs(nextHeuristic - currHeuristic);
        pair<int, int> tempPair = {row, column - 1};
        double tempCost = matrix[row][column - 1];
        if (tempCost != -1) {
            adj.push_back(new Node<pair<int, int>>(tempPair, tempCost + curr->getCost() + combinedHeuristic, curr));
        }
    }

    // If the node is not in the last column
    if (column + 1 < numOfColumns) {
        nextHeuristic =  abs(goal->getNodeValue().first - row) + abs(goal->getNodeValue().second - column + 1);
        combinedHeuristic = abs(nextHeuristic - currHeuristic);
        pair<int, int> tempPair = {row, column + 1};
        double tempCost = matrix[row][column + 1];
        if (tempCost != -1) {
            adj.push_back(new Node<pair<int, int>>(tempPair, tempCost + curr->getCost() + combinedHeuristic, curr));
        }
    }

    return adj;
}
