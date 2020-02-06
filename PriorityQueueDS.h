//
// Created by ardeus on 03/02/2020.
//

#ifndef EX4_PRIORITYQUEUEDS_H
#define EX4_PRIORITYQUEUEDS_H

#include "DataStructure.h"
#include <queue>

/**
 * PriorityQueueDS class
 */
template <typename T>
class PriorityQueueDS : public DataStructure<T> {
private:
    // The open list of the DS, in this case - Queue
    priority_queue<Node<T>*> openList;
public:
    // Get status of the queue
    virtual bool isOpenEmpty() { return openList.empty(); }

    // Get top value of the queue
    virtual Node<T>* getTop() { return openList.top(); }

    // Push value to queue
    virtual void pushOpen(Node<T>* node) { openList.push(node); }

    // Pop top value from the queue
    virtual Node<T>* popOpen()
    {
        Node<T> node = openList.top();
        openList.pop();
        return node;
    }

    // Get the queue size
    virtual unsigned long size() { openList.size(); }

    // Check if node is found in queue
    virtual bool isInClosed(Node<T>* node)
    {
        // A vector to store in the nodes in the queue
        vector<Node<T>*> nodes;

        // Assuming the node isn't found
        bool isFound = false;

        // A temp node to store info
        Node<T>* currNode;

        // Going over the queue
        while (!isOpenEmpty())
        {
            currNode = openList.pop();
            nodes.push_back(currNode);
        }

        // Checking if the node exists in vector while restoring the queue
        for (int i = 0; i < nodes.size(); i++)
        {
            openList.push(nodes[i]);
            if (nodes[i] == node)
                isFound = true;
        }

        return isFound;
    }
};


#endif //EX4_PRIORITYQUEUEDS_H
