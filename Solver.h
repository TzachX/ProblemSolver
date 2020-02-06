//
// Created by ardeus on 30/01/2020.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H

namespace server_side
{
    template<typename Problem, typename Solution>
    class Solver {
    public:
        virtual Solution solve(Problem p) = 0;
    };
}

#endif //EX4_SOLVER_H
