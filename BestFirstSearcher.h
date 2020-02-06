//
// Created by ardeus on 02/02/2020.
//

#ifndef EX4_BESTFIRSTSEARCHER_H
#define EX4_BESTFIRSTSEARCHER_H


#include "TraceBackSearcher.h"
#include "PriorityQueueDS.h"

template <typename T>
class BestFirstSearcher : public TraceBackSearcher<T>
{
private:
    PriorityQueueDS<T> pq;
public:
    // Override to the Searcher interface
};


#endif //EX4_BESTFIRSTSEARCHER_H
