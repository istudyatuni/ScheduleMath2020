cmake_minimum_required (VERSION 2.8)

project(shedule)
set(CMAKE_CXX_FLAGS "-Wall -Os")#-w for disable all warnings
include_directories("include")
add_executable(shedule src/main.cpp src/table.cpp)