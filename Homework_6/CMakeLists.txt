cmake_minimum_required(VERSION 3.22)

project(my_wc)

file(GLOB my_wc_files "./*.cpp")
add_executable(my_wc ${my_wc_files})
