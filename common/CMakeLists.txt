add_library(porklib_common "")

target_sources(porklib_common PRIVATE
        porklib/common.cpp)

target_include_directories(porklib_common PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})
