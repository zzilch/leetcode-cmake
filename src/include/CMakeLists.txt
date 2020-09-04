add_library(leetcode INTERFACE)
add_library(catch INTERFACE)
target_include_directories(leetcode INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})