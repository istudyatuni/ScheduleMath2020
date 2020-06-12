cmake_minimum_required (VERSION 2.8)

project(shedule)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Os")
set(CMAKE_CXX_FLAGS_RELEASE "-w -Os")

set(SOURCE src/main.cpp src/table.cpp src/shedule.cpp src/criteria.cpp)

include_directories("include")
add_executable(shedule ${SOURCE})