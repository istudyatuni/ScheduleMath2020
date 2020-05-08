cmake_minimum_required (VERSION 2.8)

project(shedule)
include_directories("include")

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_FLAGS "-Wall -Os -L/usr/local/lib")

add_executable(main src/main.cpp src/class.cpp)