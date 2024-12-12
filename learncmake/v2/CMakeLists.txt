cmake_minimum_required(VERSION 3.5)

project(CALC)

# 设置 c++ 标准
set(CMAKE_CXX_STANDARD 11)

# 设置变量值 默认string类型
# set(SRC_LIST main.cpp add.cpp sub.cpp mult.cpp div.cpp)

# aux_source_directory(${PROJECT_SOURCE_DIR} SRC_LIST) #PROJECT_SOURCE_DIR cmake dir 这个路径

file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp) # cmakelist的路径

# 指定头文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(calc SHARED ${SRC_LIST})

# 设置库文件路径
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)


# 输出路径
# set(EXECUTABLE_OUTPUT_PATH /root/work/learncmake/bin)


# 知识点

# cmake_minimum_required(VERSION 3.5)
# project(CALC)
# set(CMAKE_CXX_STANDARD 11) 设置宏
# set(SRC_LIST main.cpp add.cpp sub.cpp mult.cpp div.cpp) 设置变量值
# aux_source_directory(${PROJECT_SOURCE_DIR} SRC_LIST) 找所有的文件
# file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp) 找所有的文件
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include) 指定头文件
# add_executable(app ${SRC_LIST}) 添加可执行文件
# add_library(calc STATIC ${SRC_LIST}) 添加库文件
# set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib) 设置库文件路径

# 动态库 静态库
# SHARED STATIC
# libNAME.so 有执行权限
# libNAME.a
# 库文件使用
# 1.库文件 2.头文件





