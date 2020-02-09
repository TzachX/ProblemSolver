//
// Created by zohar Rafter and Tzach Cohen
//visit our Git : https://github.com/TzachX/ProblemSolver
//

#include <string>
#include "MyParallelServer.h"
#include "MyClientHandler.h"
#include "pathSolver.h"
#include "FileCacheManager.h"

using namespace std;
int main(int argv, char* args[]){

    int port;
if(argv==2){
    port=stod(args[1]);
}
else{
    port = 5400;

}

MyParallelServer parServer;
ClientHandler* c = new MyClientHandler(new PathSolver(),   new FileCacheManager("Sol.txt") );
parServer.open(port, c);
parServer.stop();
return 0 ;




}