cmake_minimum_required(VERSION 3.25)
project(grafos)

set(CMAKE_CXX_STANDARD 17)

add_executable(grafos main.cpp
        MyGraph.cpp
        MyGraph.h)
