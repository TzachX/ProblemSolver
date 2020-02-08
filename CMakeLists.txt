cmake_minimum_required(VERSION 3.15)
project(Ex4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ex4 Server.h ClientHandler.h Solver.h MySerialServer.cpp MySerialServer.h MyTestClientHandler.cpp MyTestClientHandler.h CacheManager.h StringReverser.cpp StringReverser.h FileCacheManager.cpp FileCacheManager.h Main.h Main.h Searchable.h Searcher.h BestFirstSearcher.h Node.h TraceBackSearcher.h DataStructure.h StackDS.h QueueDS.h PriorityQueueDS.h DFSSearcher.h BFSSearcher.h AStarSearcher.h MatrixSearchable.cpp MatrixSearchable.h)