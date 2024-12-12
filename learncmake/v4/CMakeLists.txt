cmake_minimum_required(VERSION 3.5)

project(CALC)

# 设置 c++ 标准
set(CMAKE_CXX_STANDARD 11)



file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp) # cmakelist的路径

# 指定头文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


# link_libraries(calc) # 链接静态库
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib2) # 指定库文件路径 
add_executable(app ${SRC_LIST})
target_link_libraries(app calc) # 链接动态库








# cmake_minimum_required(VERSION 3.5)
# project(CALC)
# set(CMAKE_CXX_STANDARD 11) 设置宏
# set(SRC_LIST main.cpp add.cpp sub.cpp mult.cpp div.cpp) 设置变量值
# aux_source_directory(${PROJECT_SOURCE_DIR} SRC_LIST) 找所有的文件
# file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp) 找所有的文件
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include) 指定头文件

# add_executable(app ${SRC_LIST}) 添加可执行文件
# set(EXECUTABLE_OUTPUT_PATH /root/work/learncmake/bin) 设置可执行文件路径
# add_library(calc STATIC ${SRC_LIST}) 添加库文件
# set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib) 设置库文件路径

# 动态库 静态库
# SHARED STATIC
# libNAME.so 有执行权限
# libNAME.a
# 库文件使用
# 1.库文件 2.头文件

# 静态库使用
# 静态库会打包的时候一起打包
# link_libraries(calc) # 链接静态库
# link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib) # 指定库文件路径 

# 动态库使用
# target_link_libraries(app calc) # 链接动态库 这个要写在最后 别的都是写在前面
# public private interface # public: 任何地方都可以使用

# 日志
# message(STATUS "This is a message")
# 级别






