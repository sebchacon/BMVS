
cmake_minimum_required(VERSION 3.27)
project(prog3)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_compile_options(-Wall -Wextra -g -pedantic)
add_executable(prog3
        prog3.cpp
        prog3test.cpp
        stuff3.cpp
)

set(CMAKE_VERBOSE_MAKEFILE OFF)