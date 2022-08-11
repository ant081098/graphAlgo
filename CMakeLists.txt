cmake_minimum_required(VERSION 3.5)

project(graphAlgo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_HEADERS graphAlgo.h
    part/vertex.h
    part/edge.h
    graph/igraph.h
    graph/graph.h
    system/isystem.h
    system/console.h
    system/file.h
    algo/ialgo.h
    algo/dfs.h
    algo/bfs.h
    algo/topsort.h
    algo/dextra.h
    algo/fordbellman.h
    algo/floid.h
    algo/bridges.h
    algo/pointjoin.h
)

set(PROJECT_SOURCES main.cpp
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

add_executable(graphAlgo ${PROJECT_HEADERS} ${PROJECT_SOURCES})
