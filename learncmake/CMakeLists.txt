cmake_minimum_required(VERSION 3.5)

project(CALC)

# 设置 c++ 标准
set(CMAKE_CXX_STANDARD 11)

# 设置变量值 默认string类型
set(SRC_LIST main.cpp add.cpp sub.cpp mult.cpp div.cpp)

# 输出路径
set(EXECUTABLE_OUTPUT_PATH /root/work/learncmake/bin)

add_executable(app ${SRC_LIST})
