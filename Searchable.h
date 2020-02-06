//
// Created by ardeus on 01/02/2020.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#include "Node.h"
// Algorithm functionality
template <typename T>
class Searchable
{
public:
    virtual Node<T> getStartingNode();
    virtual Node<T> getEndingNode();
    virtual ~Searchable(){}
};


#endif //EX4_SEARCHABLE_H
