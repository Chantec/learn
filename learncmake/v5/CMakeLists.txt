cmake_minimum_required(VERSION 3.5)
project(CALC)
# 设置 c++ 标准
set(CMAKE_CXX_STANDARD 11)

# 库路径
set(LIBPATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
# 可执行路径
set(EXEPATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
# 头文件路径
set(INCPATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
# 库文件名字
set(CALCLIB calc)
# 可执行文件名字
set(APPNAME app)

add_subdirectory(src)
add_subdirectory(test)







# 笔记

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

# 宏-自定义
# add_definitions(-DDEBUG)

# 子目录
# add_subdirectory(test)

# 日志
# message(STATUS "This is a message")
# 级别

# 变量操作
# set(变量名 ${变量名} ...)
# 拼接
# list(APPEND list_name ${item})
# 移除
# list(REMOVE_ITEM list_name ${item})
# 获取长度
# list(LENGTH list_name length)
# 得到索引
# list(GET list_name index item)
# 连接
# list(JOIN list_name separator result)
# 查找
# list(FIND list_name item index)
# 插入
# list(INSERT list_name index item)
# 反转
# list(REVERSE list_name)
# 排序
# list(SORT list_name)







