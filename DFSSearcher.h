//
// Created by ardeus on 08/02/2020.
//

#ifndef EX4_DFSSEARCHER_H
#define EX4_DFSSEARCHER_H


#include "StackDS.h"
#include "Searchable.h"
#include "Searcher.h"
#include "TraceBackSearcher.h"

template <typename T>
class DFSSearcher : public TraceBackSearcher<T> {
private:
    StackDS<T> stack;
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
        stack.pushOpen(startNode);

        while (!stack.isOpenEmpty())
        {
            this->EvalNodesCount++;
            currNode = stack.popOpen();

            if (*currNode == *endNode)
            {
                vector<Node<T>*> output = this->getOutputTrace(startNode, currNode);
                this->eraseData(output, &stack);
                return output;
            }

            if (!stack.isInClosed(currNode))
            {
                stack.pushClosed(currNode);
                vector<Node<T>*> paths = searchable->getPaths(currNode);
                for (Node<T>* currNode : paths)
                {
                    stack.pushOpen(currNode);
                }
            }
            else
                delete (currNode);

            vector<Node<T>*> newVector;
            this->eraseData(newVector, &stack);
            return newVector;
        }
    }
};


#endif //EX4_DFSSEARCHER_H
