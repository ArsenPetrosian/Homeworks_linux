cmake_minimum_required(VERSION 3.22)

project(merge_sort)

file(GLOB merge_sort_files "./*.cpp")
add_executable(merge_sort ${merge_sort_files})