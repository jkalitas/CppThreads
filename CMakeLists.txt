cmake_minimum_required(VERSION 3.10)
project(CppThreads)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -O3 -fPIC -lpthread")

add_executable(CppThreads main.cpp FooClass.h FooClass1.h)
target_link_libraries(CppThreads pthread)