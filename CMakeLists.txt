cmake_minimum_required(VERSION 3.0)
project(auto_brightness)

set(CMAKE_C_STANDARD 11)

add_executable(auto_brightness main.c v4l2_utils.c image_utils.c)

