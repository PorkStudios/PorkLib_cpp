cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(porklib_cpp)

# Define libraries

add_library(porklib_cpp "")

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp" "*.h")
list(FILTER sources EXCLUDE REGEX "/dev/*")
target_sources(porklib_cpp PRIVATE ${sources})

target_include_directories(porklib_cpp PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# Define dev
add_subdirectory(dev)
