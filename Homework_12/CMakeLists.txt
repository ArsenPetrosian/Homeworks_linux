cmake_minimum_required(VERSION 3.5)

project(wait_for_signal)

file(GLOB wait_for_signal_files "./*.cpp")
add_executable(wait_for_signal ${wait_for_signal_files})