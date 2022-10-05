cmake_minimum_required(VERSION 3.5)

project(Polinomial)

add_executable(Polinomial Pol.cpp src/Polinomial.cpp)

target_include_directories(Polinomial PRIVATE
"./include")
