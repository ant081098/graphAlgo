cmake_minimum_required(VERSION 3.5)

project(builderGraph LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES main.cpp
    graphAlgo.h
    part/vertex.cpp
    part/edge.cpp
    graph/igraph.cpp
    graph/graph.cpp
    system/isystem.cpp
    system/console.cpp
    system/file.cpp
    algo/ialgo.cpp
    algo/dfs.cpp
    algo/bfs.cpp
    algo/topsort.cpp
    algo/dextra.cpp
    algo/fordbellman.cpp
    algo/floid.cpp
    algo/bridges.cpp
    algo/pointjoin.cpp
)

add_executable(graphAlgo ${SOURCES})
