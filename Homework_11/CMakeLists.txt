cmake_minimum_required(VERSION 3.22)

project(redirection)

file(GLOB redirection_files "./*.cpp")
add_executable(redirection ${redirection_files})