cmake_minimum_required(VERSION 3.22)

project(my_cat)

file(GLOB my_cat_files "./*.cpp")
add_executable(my_cat ${my_cat_files})