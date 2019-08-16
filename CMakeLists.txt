cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(porklib_cpp)

# Define libraries

add_library(porklib_cpp "")

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/source/*.cpp" "${PROJECT_SOURCE_DIR}/source/*.s")
file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/source/*.h")
#message(${sources})
target_sources(porklib_cpp PRIVATE ${sources} PUBLIC ${headers})

target_include_directories(porklib_cpp PUBLIC ${PROJECT_SOURCE_DIR}/source/)

# Define dev
add_subdirectory(dev)
