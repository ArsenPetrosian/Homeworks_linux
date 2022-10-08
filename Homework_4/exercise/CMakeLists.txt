cmake_minimum_required(VERSION 3.22)

project(Calculate_average)

file(GLOB Calculate_average_files "./*.cpp")
add_executable(Calculate_average ${Calculate_average_files})