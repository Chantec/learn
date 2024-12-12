cmake_minimum_required(VERSION 3.5)

project(CALC)

# 设置 c++ 标准
set(CMAKE_CXX_STANDARD 11)

# 设置变量值 默认string类型
# set(SRC_LIST main.cpp add.cpp sub.cpp mult.cpp div.cpp)

# aux_source_directory(${PROJECT_SOURCE_DIR} SRC_LIST) #PROJECT_SOURCE_DIR cmake dir 这个路径

file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp) # cmakelist的路径

# 指定头文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


# 输出路径
set(EXECUTABLE_OUTPUT_PATH /root/work/learncmake/bin)



add_executable(app ${SRC_LIST})

# cmake_minimum_required(VERSION 3.5)
# project(CALC)
# set(CMAKE_CXX_STANDARD 11) 设置宏
# set(SRC_LIST main.cpp add.cpp sub.cpp mult.cpp div.cpp) 设置变量值
# aux_source_directory(${PROJECT_SOURCE_DIR} SRC_LIST) 找所有的文件
# file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp) 找所有的文件
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include) 指定头文件

# 动态库 静态库




