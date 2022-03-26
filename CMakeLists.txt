cmake_minimum_required(VERSION 3.21)
project(algorithms_c)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/include)

add_executable(algorithms_c_test
        src/test.cpp)

add_executable(xtensor
        # src/xtensor/xtensorBasics.cpp
        src/xtensor/expressionsAndLazyEvaluation.cpp)

add_executable(binary_tree
        src/hackerrank/data-structures/trees/easy/BinaryTree.cpp)

add_executable(power_sum
        src/hackerrank/algorithms/recursion/medium/PowerSum.cpp)

add_executable(equal
        src/hackerrank/algorithms/implementation/medium/Equal.cpp)

# GMP (Big number support)
# pkg-config --cflags gmp
include_directories(/usr/local/Cellar/gmp/6.2.1_1/include)
# pkg-config --libs gmp
target_link_libraries(algorithms_c_test /usr/local/Cellar/gmp/6.2.1_1/lib/libgmp.a)


# xtensor (C++ numpy like)
include_directories(
        /usr/local/Cellar/xtensor/0.24.0/include
)
# /usr/local/Cellar/xtensor/0.24.0/lib/cmake/xtensor