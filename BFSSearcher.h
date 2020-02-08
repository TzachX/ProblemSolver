//
// Created by ardeus on 08/02/2020.
//

#ifndef EX4_BFSSEARCHER_H
#define EX4_BFSSEARCHER_H


#include "Searcher.h"
#include "TraceBackSearcher.h"
#include "QueueDS.h"

template <typename T>
class BFSSearcher : public TraceBackSearcher<T> {
private:
    QueueDS<T> queue;
public:
    // Override to the Searcher interface
    vector<Node<T>> search (Searchable<T>* searchable)
    {
        this->EvalNodesCount = 0;

        // Storing the starting + ending nodes
        Node<T>* startNode = searchable->getStartingNode();
        Node<T>* endNode = searchable->getEndingNode();
        Node<T>* currNode;

        // Insert the starting node to the priority queue
        queue.pushOpen(startNode);

        while (!queue.isOpenEmpty())
        {
            this->EvalNodesCount++;
            currNode = queue.popOpen();

            if (*currNode == *endNode)
            {
                vector<Node<T>*> output = this->getOutputTrace(startNode, currNode);
                this->eraseData(output, &queue);
                return output;
            }

            vector<Node<T>*> paths = searchable->getPaths(currNode);
            for (Node<T>* currNode : paths)
            {
                if (!queue.isInClosed(currNode))
                {
                    queue.pushOpen(currNode);
                    queue.pushClosed(currNode);
                }
                else
                    delete(currNode);
            }

            vector<Node<T>*> newVector;
            this->eraseData(newVector, &queue);
            return newVector;
        }
    }

    virtual void eraseData(vector<Node<T>*> output, DataStructure<T>* ds) {
        Node<T> *currNode;
        while (!ds->emptyOpen()) {
            currNode = ds->popOpen();
            if (!ds->isInClosed(currNode))
                delete (currNode);
        }
        while (!ds->emptyClosed()) {
            currNode = ds->popFromClosed();
            for (int i = 0; i < output.size(); i++) {
                if (output[i] == currNode)
                    break;
                if (i == output.size() - 1)
                    delete (currNode);
            }
        }
    }
};


#endif //EX4_BFSSEARCHER_H
