//
// Created by Tzach on 03/02/2020.
//

#ifndef EX4_STACKDS_H
#define EX4_STACKDS_H


#include <stack>
#include "DataStructure.h"

/**
 * StackDS class
 */
template <typename T>
class StackDS : public DataStructure<T>
{
private:
    // The open list of the DS, in this case - Stack
    stack<Node<T>*> openList;
public:
    // Get status of the stack
    bool isOpenEmpty() { return openList.empty(); }

    // Get top value of the stack
    Node<T>* getTop() { return openList.top(); }

    // Push value to stack
    void pushOpen(Node<T>* node) { openList.push(node); }

    // Pop top value from the stack
    Node<T>* popOpen()
    {
        Node<T> node = openList.top();
        openList.pop();
        return node;
    }
};

#endif //EX4_STACKDS_H
