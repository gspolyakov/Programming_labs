cmake_minimum_required(VERSION 3.24)
project(Programming_labs)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(lab01)

add_executable(Programming_labs
        lab01.h lab02.h lab03.h lab04.cpp funcs.h)
