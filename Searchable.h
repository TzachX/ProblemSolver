//
// Created by ardeus on 01/02/2020.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#include "Node.h"
#include <vector>
using namespace std;
// Algorithm functionality
template <typename T>
class Searchable
{
public:
    virtual Node<T>* getStartingNode() = 0;
    virtual Node<T>* getEndingNode() = 0;
    virtual vector<Node<T>*> getPaths(Node<T>* node) = 0;
    virtual vector<Node<T>*> getPaths(Node<T>* start, Node<T>* end) = 0;
    virtual ~Searchable(){}
};


#endif //EX4_SEARCHABLE_H
