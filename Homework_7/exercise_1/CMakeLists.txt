cmake_minimum_required(VERSION 3.22)

project(decrep)

file(GLOB decrep_files "./*.cpp")
add_executable(decrep ${decrep_files})