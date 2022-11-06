cmake_minimum_required(VERSION 3.22)

project(redir)

file(GLOB redir_files "./*.cpp")
add_executable(redir ${redir_files})