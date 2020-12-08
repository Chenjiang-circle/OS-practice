cmake_minimum_required(VERSION 3.17)
project(Mymalloc C)

set(CMAKE_C_STANDARD 99)

add_executable(Mymalloc main.c Mymalloc.h Mymalloc.cpp)