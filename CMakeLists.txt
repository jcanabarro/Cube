cmake_minimum_required(VERSION 3.7)
project(Cube)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        blindsearch.cpp
        cube.cpp
        heuristicsearch.cpp
        shuffle.cpp)

add_executable(Cube ${SOURCE_FILES})