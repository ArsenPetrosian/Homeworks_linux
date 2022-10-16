cmake_minimum_required(VERSION 3.22)

project(Bash_or)

file(GLOB Bash_or_files "./*.cpp")
add_executable(Bash_or ${Bash_or_files})
