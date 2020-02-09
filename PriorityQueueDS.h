//
// Created by ardeus on 09/02/2020.
//

#ifndef FLIGHTSIM2ND_PRIORITYQUEUEDS_H
#define FLIGHTSIM2ND_PRIORITYQUEUEDS_H

#include "DataStructure.h"
#include "OrganizedPriorityQueue.h"
#include "Node.h"
#include <queue>

template <typename T>
class PriorityQueueDS : public DataStructure<T> {
private:
    // The open list of the DS, in this case - Queue
    OrganizedPriorityQueue<T> openList;
public:
    // Get status of the queue
    virtual bool isOpenEmpty() { return openList.isOpenEmpty(); }

    // Get top value of the queue
    virtual Node<T>* getTop() { return openList.getTop(); }

    // Push value to queue
    virtual void pushOpen(Node<T>* node) { openList.pushOpen(node); }

    // Pop top value from the queue
    virtual Node<T>* popOpen()
    {
        openList.popOpen();
    }

    // Get the queue size
    virtual unsigned long size() { openList.size(); }

    Node<T>* findInOpen(Node<T>* state) {
        return openList.findInOpen(state);
    }

    void eraseFromOpen(Node<T>* state) {
        openList.eraseFromOpen(state);
    }

    bool isInOpen(Node<T>* state) {
        return openList.isInOpen(state);
    }
};


#endif //FLIGHTSIM2ND_PRIORITYQUEUEDS_H
