cmake_minimum_required(VERSION 3.1)

project(test)
set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable(app main.cpp Buffer.cpp Log.cpp)
