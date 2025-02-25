cmake_minimum_required(VERSION 3.28)
project(wheels)
find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 23)

add_executable(run_tests
        Math/combination.test.cpp
        Math/combination.cpp
        Math/combination.h)

target_link_libraries(run_tests GTest::GTest GTest::Main)

enable_testing()
add_test(NAME wheels_test COMMAND run_tests)
