cmake_minimum_required(VERSION 3.20)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

include_directories(model)
include_directories(controller)

add_executable(lab1 main.cpp)
