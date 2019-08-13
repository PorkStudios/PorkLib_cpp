add_library(porklib_common "")

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp" "*.h")
target_sources(porklib_common PRIVATE ${sources})

target_include_directories(porklib_common PUBLIC ${CMAKE_CURRENT_LIST_DIR})
