add_executable(porklib_cpp_dev "")

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp" "*.h")
target_sources(porklib_cpp_dev PRIVATE ${sources})

target_include_directories(porklib_cpp_dev PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(porklib_cpp_dev porklib_cpp)
