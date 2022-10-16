cmake_minimum_required(VERSION 3.22)

project(Bash_and)

file(GLOB Bash_and_files "./*.cpp")
add_executable(Bash_and ${Bash_and_files})