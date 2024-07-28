cmake_minimum_required(VERSION 3.28)
project(wheels)

set(CMAKE_CXX_STANDARD 23)

add_executable(wheels
        UnionFindSet/union_find_set.h
        UnionFindSet/union_find_set.cpp
        PrefixTree/prefix_tree.h
        PrefixTree/prefix_tree.cpp
        Sort/quick_sort.cpp
        Heap/heap.cpp
        Heap/heap.h
        Sort/heap_sort.cpp
        Graph/Floyd.cpp)
