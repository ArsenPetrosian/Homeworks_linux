cmake_minimum_required(VERSION 3.22)

project(vector)

add_library(MyVector STATIC src/MyVector.cpp)

add_executable(vector main.cpp)

target_include_directories(vector PRIVATE
"./include")
target_link_libraries(vector PRIVATE MyVector)