//
// Created by ardeus on 30/01/2020.
//

#include "StringReverser.h"

string server_side::StringReverser::solve(string p) {
    int stringLen = p.length();
    int n = stringLen - 1;
    for(int i = 0; i < (stringLen / 2); i++){
        //Using the swap method to switch values at each index
        swap(p[i], p[n]);
        n = n-1;

    }
    return p;
}
