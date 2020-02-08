//
// Created by ardeus on 02/02/2020.
//

#ifndef EX4_DATASTRUCTURE_H
#define EX4_DATASTRUCTURE_H

using namespace std;
#include "Node.h"
#include <vector>
#include <algorithm>

template <typename T>
class DataStructure
{
protected:
    vector<Node<T>*> closedList;
public:
    virtual bool isOpenEmpty() = 0;
    virtual Node<T>* popOpen() = 0;
    virtual void pushOpen(Node<T>* node) = 0;
    virtual Node<T>* getTop() = 0;
    virtual bool isInOpen(Node<T>* node) = 0;
    virtual bool isClosedEmpty() { return closedList.empty(); }
    virtual Node<T>* popClosed() { return closedList.pop_back(); }
    virtual void pushClosed(Node<T>* node) { closedList.push_back(node); }
    virtual bool isInClosed(Node<T>* node) { return find(closedList.begin(), closedList.end(), node) != closedList.end(); }
};


#endif //EX4_DATASTRUCTURE_H
