//
// Created by ardeus on 03/02/2020.
//

#ifndef EX4_PRIORITYQUEUE_H
#define EX4_PRIORITYQUEUE_H

#include "DataStructure.h"
#include <queue>

/**
 * ArrangeQueue class
 */
template <typename T>
class ArrangeQueue
{
public:
    // Define rule that orders the elements of the priority queue in a certain way
    bool operator()(Node<T> *cmp, Node<T>* other) { return cmp->getCost() > other->getCost(); }
};

/**
 * OrganizedPriorityQueue class
 */
template <typename T>
class OrganizedPriorityQueue {
private:
    // A special priority queue that orders its elements according to the rule in ArrangeQueue
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

    // Find the given node in the open list
    Node<T>* findInOpen(Node<T>* node)
    {
        vector<Node<T>*> nodes;
        Node<T> *currNode;
        Node<T> *returnNode = nullptr;

        // Transfer all the nodes to a vector and check if the node is in pq
        while (!isOpenEmpty())
        {
            currNode = popOpen();
            nodes.push_back(currNode);
            if (*currNode == *node)
            {
                returnNode = currNode;
                break;
            }
        }

        // Restoring pq
        for (int i = 0; i < nodes.size(); ++i) { pushOpen(nodes[i]); }
        return returnNode;
    }

    // Erase the given node in the open list
    void eraseFromOpen(Node<T>* node)
    {
        vector<Node<T>*> nodes;
        Node<T> *currNode;

        // Transfer all the nodes to a vector and check if the node is in pq
        while (!isOpenEmpty())
        {
            currNode = popOpen();
            if (currNode == node)
            {
                delete (currNode);
                break;
            }
            nodes.push_back(currNode);
        }

        // Restoring pq
        for (int i = 0; i < nodes.size(); ++i) { pushOpen(nodes[i]); }
    }

    // Check if the given node is in the open list
    bool isInOpen(Node<T>* node) {
        vector<Node<T>*> nodes;
        Node<T> *currNode;
        bool inFound = false;

        // Transfer all the nodes to a vector and check if the node is in pq
        while (!isOpenEmpty())
        {
            currNode = popOpen();
            nodes.push_back(currNode);
            if (*currNode == *node)
            {
                inFound = true;
                break;
            }
        }

        // Restoring pq
        for (int i = 0; i < nodes.size(); ++i) { pushOpen(nodes[i]); }
        return inFound;
    }
};


#endif //EX4_PRIORITYQUEUE_H
