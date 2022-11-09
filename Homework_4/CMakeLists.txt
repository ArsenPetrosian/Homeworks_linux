cmake_minimum_required(VERSION 3.22)

project(calculate_average)

file(GLOB calculate_average_files "./*.cpp")
add_executable(calculate_average ${calculate_average_files})
