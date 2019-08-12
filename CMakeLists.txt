cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)

project(porklib_cpp)

# Define libraries
add_subdirectory(common)

add_library(porklib_cpp "")
target_link_libraries(porklib_cpp porklib_common)
target_sources(porklib_cpp PRIVATE)
target_include_directories(porklib_cpp PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

add_executable(porklib_cpp_dev dev.cpp)
target_link_libraries(porklib_cpp_dev
        porklib_cpp)
