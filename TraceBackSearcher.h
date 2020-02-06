//
// Created by ardeus on 02/02/2020.
//

#ifndef EX4_TRACEBACKSEARCHER_H
#define EX4_TRACEBACKSEARCHER_H

using namespace std;
#include "Searcher.h"
#include "DataStructure.h"
#include <vector>
template <typename T>
class TraceBackSearcher : public Searcher<T, vector<Node<T>*>>
{
protected:
    virtual vector<Node<T>*> getOutputTrace(Node<T>* start, Node<T>* end)
    {
        // outputTrace will be the reverse of pathTrace, which is tracing of the path the algorithm found
        vector <Node<T>*> pathTrace;
        vector <Node<T>*> outputTrace;
        Node<T>* currNode = end;

        while (*currNode != *start)
        {
            pathTrace.push_back(currNode);
            currNode = currNode->getSource();
        }
        pathTrace.push_back(start);

        for (unsigned long i = pathTrace.size(); i > 0; i--)
            outputTrace.push_back(pathTrace[i - 1]);

        return outputTrace;
    }

    virtual void eraseData(vector<Node<T>*> output, DataStructure<T>* ds)
    {
        Node<T> *currNode;
        while (!ds->emptyOpen()) {
            delete (ds->popFromOpen());
        }
        while (!ds->emptyClosed())
        {
            currNode = ds->popFromClosed();
            for (int i = 0; i < output.size(); i++)
            {
                if (output[i] == currNode)
                    break;
                if (i == output.size() - 1)
                    delete (currNode);
            }
        }
    }
};


#endif //EX4_TRACEBACKSEARCHER_H
