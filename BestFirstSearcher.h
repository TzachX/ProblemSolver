//
// Created by tzach on 02/02/2020.
//

#ifndef EX4_BESTFIRSTSEARCHER_H
#define EX4_BESTFIRSTSEARCHER_H



#include "TraceBackSearcher.h"
#include "PriorityQueueDS.h"

template <typename T>
/***
 * best Sercher algorithm
 * @tparam T any object node
 */
class BestFirstSearcher : public TraceBackSearcher<T>
{
private:
    PriorityQueueDS<T> pq;
public:
    // This function implements the actual best first search algorithm
    vector<Node<T>*> search (Searchable<T>* searchable)
    {
        // Initialize the number of the nodes visited
        this->EvalNodesCount = 0;

        // Defining the starting + ending nodes
        Node<T>* startNode = searchable->getStartingNode();
        Node<T>* endNode = searchable->getEndingNode();

        // Insert the starting node to the priority queue
        pq.pushOpen(startNode);

        // While the priority queue is not empty
        while (!pq.isOpenEmpty())
        {
            this->EvalNodesCount++;

            // Get the neighbor node with the lowest cost
            Node<T>* min = pq.popOpen();
            pq.pushClosed(min);

            // If the current node is the ending node, return the path
            if (*min == *endNode)
            {
                vector<Node<T>*> output = this->getOutputTrace(startNode, min);
                this->eraseData(output, &pq);
                return output;
            }

            // Iterate over the paths near the current node
            vector<Node<T>*> paths = searchable->getPaths(min);
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
        }

        // If we got here it means there's no path. Sends an empty vector
        vector<Node<T>*> newVector;
        this->eraseData(newVector, &pq);
        return newVector;
    }
};

#endif //EX4_BESTFIRSTSEARCHER_H