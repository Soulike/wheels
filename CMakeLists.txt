cmake_minimum_required(VERSION 3.28)
project(wheels)

set(CMAKE_CXX_STANDARD 23)

add_executable(wheels
        UnionFindSet/union_find_set.cpp
        PrefixTree/prefix_tree.h
        PrefixTree/prefix_tree.cpp)