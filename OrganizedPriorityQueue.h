//
// Created by ardeus on 03/02/2020.
//

#ifndef EX4_PRIORITYQUEUE_H
#define EX4_PRIORITYQUEUE_H

#include "DataStructure.h"
#include <queue>

template <typename T>
class ArrangeQueue {
public:
    bool operator()(Node<T> *cmp, Node<T>* other) { return cmp->getCost() > other->getCost(); }
};

/**
 * OrganizedPriorityQueue class
 */
template <typename T>
class OrganizedPriorityQueue {
private:
    // The open list of the DS, in this case - Queue
    priority_queue<Node<T>*, vector<Node<T>*>, ArrangeQueue<T>>  pq;
public:
    // Get status of the queue
    virtual bool isOpenEmpty() { return pq.empty(); }

    // Get top value of the queue
    virtual Node<T>* getTop() { return pq.top(); }

    // Push value to queue
    virtual void pushOpen(Node<T>* node) { pq.push(node); }

    // Pop top value from the queue
    virtual Node<T>* popOpen()
    {
        Node<T>* node = pq.top();
        pq.pop();
        return node;
    }

    // Get the queue size
    virtual unsigned long size() { pq.size(); }

    Node<T>* findInOpen(Node<T>* state) {
        vector<Node<T>*> nodes;
        vector<Node<T>*> states;
        Node<T> *tempState;
        Node<T> *retState = nullptr;

        // pop all states to a vector and checking if the state exists in pq
        while (!isOpenEmpty()) {
            tempState = popOpen();
            states.push_back(tempState);
            if (*tempState == *state) {
                retState = tempState;
                break;
            }
        }

        // return all the states to pq
        for (int i = 0; i < states.size(); ++i) {
            pushOpen(states[i]);
        }
        return retState;
    }

    void eraseFromOpen(Node<T>* state) {
        vector<Node<T>*> states;
        Node<T> *tempState;

        // pop all states to a vector and checking if the state exists in pq
        while (!isOpenEmpty()) {
            tempState = popOpen();
            if (tempState == state) {
                delete (tempState);
                break;
            }
            states.push_back(tempState);
        }

        // return all the states to pq
        for (int i = 0; i < states.size(); ++i) {
            pushOpen(states[i]);
        }
    }

    bool isInOpen(Node<T>* state) {
        vector<Node<T>*> states;
        Node<T> *tempState;
        bool exist = false;

        // pop all states to a vector and checking if the state exists in pq
        while (!isOpenEmpty()) {
            tempState = popOpen();
            states.push_back(tempState);
            if (*tempState == *state) {
                exist = true;
                break;
            }
        }

        // return all the states to pq
        for (int i = 0; i < states.size(); ++i) {
            pushOpen(states[i]);
        }
        return exist;
    }
};


#endif //EX4_PRIORITYQUEUE_H
