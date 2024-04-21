cmake_minimum_required(VERSION 3.28)
project(wheels)

set(CMAKE_CXX_STANDARD 14)

add_executable(wheels
        UnionFindSet/union_find_set.cpp)