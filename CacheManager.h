//
// Created by ardeus on 30/01/2020.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H

#include <string>
using namespace std;
namespace server_side {
    class CacheManager {
    public:
        virtual bool isSolutionFound(string p) = 0;
        virtual string getSolution(string p) = 0;
        virtual void storeSolution(string p, string s) = 0;
        virtual ~CacheManager(){}
    };
}


#endif //EX4_CACHEMANAGER_H
