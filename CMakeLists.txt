cmake_minimum_required(VERSION 3.16)

project(base64 VERSION 0.0.2)

option(BUILD_STATIC "" ON)
option(BUILD_SHARED "" OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)

include_directories(include/)

add_executable(app src/main.cpp)

if(BUILD_STATIC)
    add_library(base_six_four STATIC src/base64.cpp)
elseif(BUILD_SHARED)
    add_library(base_six_four SHARED src/base64.cpp)
endif()

target_link_libraries(app PRIVATE base_six_four)

target_compile_options(app PRIVATE "-Wall")
