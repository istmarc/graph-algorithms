cmake_minimum_required(VERSION 3.2)

project(test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -O2")

add_executable(test test/Test.cxx)
target_include_directories(test PUBLIC ./)

add_executable(ShortestPaths test/TestShortestPaths.cxx)
target_include_directories(ShortestPaths PUBLIC ./)

add_executable(Bipartite test/TestBipartite.cxx)
target_include_directories(Bipartite PUBLIC ./)

add_executable(ConnectedComponents test/TestConnectedComponents.cxx)
target_include_directories(ConnectedComponents PUBLIC ./)
