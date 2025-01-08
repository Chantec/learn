cmake_minimum_required(VERSION 3.5)
project(test)
# 设置 c++ 标准
set(CMAKE_CXX_STANDARD 11)
add_executable(app testconfig.cpp
        blockqueue.h)
