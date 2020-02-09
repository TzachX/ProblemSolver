//
// Created by ardeus on 01/02/2020.
//

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H

#include <unordered_map>
#include "CacheManager.h"

namespace server_side {
    class FileCacheManager : public CacheManager {
    private:
        //a cache is comprised of a hash map, a file name and a mutex to handle data
        unordered_map<string, string> solutionMap;
        string fileName;
        pthread_mutex_t mutex;
    public:
        bool isSolutionFound(string p) override ;
        void storeSolution(string p, string s) override;
        ~FileCacheManager() override { pthread_mutex_destroy(&mutex); }
        string getSolution(string p) override;
        FileCacheManager(string name);
    };
}

#endif //EX4_FILECACHEMANAGER_H
