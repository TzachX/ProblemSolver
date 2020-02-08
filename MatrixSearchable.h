//
// Created by ardeus on 08/02/2020.
//

#ifndef EX4_MATRIXSEARCHABLE_H
#define EX4_MATRIXSEARCHABLE_H


#include "Searchable.h"

class MatrixSearchable : public Searchable<pair<int, int>>
{
private:
    vector<vector<double>> matrix;
    Node<pair<int, int>>* start;
    Node<pair<int, int>>* end;
public:
    // Constructor
    MatrixSearchable(const vector<vector<double>> &matrixTable);

    ~MatrixSearchable(){ delete(end); }

    Node<pair<int, int>>* getStartNode() { return start; }

    Node<pair<int, int>>* getEndNode() { return end; }

    vector<Node<pair<int, int>>*> getPaths(Node<pair<int, int>>* node);

    vector<Node<pair<int, int>>*> getPaths(Node<pair<int, int>>* curr, Node<pair<int, int>>* goal);
};


#endif //EX4_MATRIXSEARCHABLE_H
