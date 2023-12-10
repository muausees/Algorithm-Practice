cmake_minimum_required(VERSION 3.26)
project(LibTest)

set(CMAKE_CXX_STANDARD 17)
# 添加Boost库
find_package(Boost)
include_directories(H:/cpp_tool_chain/Boost_1_82_0/)
include_directories(H:/cpp_tool_chain/OIerTemplateLib)

add_executable(LibTest main.cpp)
