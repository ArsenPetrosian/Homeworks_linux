cmake_minimum_required(VERSION 3.22)

project(wc_command)

file(GLOB wc_command_files "./*.cpp")
add_executable(wc_command ${wc_command_files})
