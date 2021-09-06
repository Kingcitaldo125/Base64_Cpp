cmake_minimum_required(VERSION 3.16)

project(base64 VERSION 1.0)

include_directories(include/)

add_executable(app src/main.cpp src/base64.cpp)
target_compile_options(app PRIVATE "-Wall")
