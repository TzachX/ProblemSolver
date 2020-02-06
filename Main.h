//
// Created by ardeus on 01/02/2020.
//

#ifndef EX4_MAIN_H
#define EX4_MAIN_H

#include <iostream>
#include <regex>
#include <thread>
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"

using namespace std;
namespace server_side
{
    namespace boot
    {
        class Main
        {
            static int main(int argCount, char* args[])
            {
                if (regex_match(args[1], regex("^\\d+")) && argCount == 2)
                {
                    Server *server = new MySerialServer();
                    server->open(atoi(args[1]),
                            new MyTestClientHandler(new StringReverser,
                                    new FileCacheManager("data.txt")));
                    this_thread::sleep_for(chrono::milliseconds(100000));
                    server->stop();
                    delete (server);
                }
            }
        };
    }
}


#endif //EX4_MAIN_H
