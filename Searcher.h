//
// Created by ardeus on 02/02/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "Searchable.h"
template <typename problem, typename solution>
class Searcher {
protected:
    int EvalNodesCount = 0;
public:
    virtual solution search(Searchable<problem>* searchable) = 0;
    virtual int getNumOfNodesEvaluated() { return EvalNodesCount; }
    virtual ~Searcher(){}
};


#endif //EX4_SEARCHER_H
