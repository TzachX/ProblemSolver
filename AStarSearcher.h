//
// Created by ardeus on 08/02/2020.
//

#ifndef EX4_ASTARSEARCHER_H
#define EX4_ASTARSEARCHER_H


#include "TraceBackSearcher.h"
#include "PriorityQueueDS.h"
template <typename T>
class AStarSearcher : public TraceBackSearcher<T>
{
private:
    PriorityQueueDS<T> pq;
public:
    // Override to the Searcher interface
    vector<Node<T>> search (Searchable<T>* searchable)
    {
        this->EvalNodesCount = 0;

        // Storing the starting + ending nodes
        Node<T>* startNode = searchable->getStartingNode();
        Node<T>* endNode = searchable->getEndingNode();

        // Insert the starting node to the priority queue
        pq.pushOpen(startNode);

        while (!pq.isOpenEmpty())
        {
            this->EvalNodesCount++;
            Node<T>* min = pq.popOpen();
            pq.pushClosed(min);

            if (*min == *endNode)
            {
                vector<Node<T>*> output = this->getOutputTrace(startNode, min);
                this->eraseData(output, &pq);
                return output;
            }


            vector<Node<T>*> paths = searchable->getPaths(min, endNode);
            for (Node<T>* currNode : paths)
            {
                if (!pq.isInClosed(currNode) && !pq.isInOpen(currNode))
                    pq.pushOpen(currNode);
                else if (!pq.isInClosed(currNode))
                {
                    Node<T>* node = pq.findInOpen(currNode);
                    if (node->getCost() > currNode->getCost())
                    {
                        pq.eraseFromOpen(node);
                        pq.pushOpen(currNode);
                    }
                    else
                        delete(currNode);
                }
                else
                    delete(currNode);
            }

            vector<Node<T>*> newVector;
            this->eraseData(newVector, &pq);
            return newVector;
        }
    }

};


#endif //EX4_ASTARSEARCHER_H
