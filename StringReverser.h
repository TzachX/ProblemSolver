//
// Created by ardeus on 30/01/2020.
//

#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H

using namespace std;

#include <iostream>
#include "Solver.h"

namespace server_side {
    class StringReverser : public Solver<string, string> {
        string solve(string p);
    };
}


#endif //EX4_STRINGREVERSER_H
