cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(porklib_cpp)

# Define libraries
add_subdirectory(common)

add_library(porklib_cpp porklib.h)
target_include_directories(porklib_cpp PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(porklib_cpp porklib_common)

# Define dev
add_subdirectory(dev)
