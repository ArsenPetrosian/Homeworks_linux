cmake_minimum_required(VERSION 3.22)

project(polish_notation)

file(GLOB polish_notation_files "./*.cpp")
add_executable(polish_notation ${polish_notation_files})