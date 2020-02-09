cmake_minimum_required(VERSION 3.15)
project(FlightSim2nd)

SET(CMAKE_CXX_FLAGS -pthread)


set(CMAKE_CXX_STANDARD 14)

add_executable(FlightSim2nd Server.h ClientHandler.h Solver.h MySerialServer.cpp MyParallelServer.cpp MyParallelServer.h MySerialServer.h MyTestClientHandler.cpp MyTestClientHandler.h CacheManager.h StringReverser.cpp StringReverser.h FileCacheManager.cpp FileCacheManager.h Main.h Main.h Searchable.h Searcher.h BestFirstSearcher.h Node.h TraceBackSearcher.h DataStructure.h StackDS.h QueueDS.h PriorityQueueDS.h DFSSearcher.h BFSSearcher.h AStarSearcher.h MatrixSearchable.cpp MatrixSearchable.h main.cpp MyClientHandler.cpp MyClientHandler.h pathSolver.h PriorityQueueDS.h OrganizedPriorityQueue.h)