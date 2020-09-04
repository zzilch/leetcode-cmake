add_subdirectory(include)

file(GLOB targets
    RELATIVE ${CMAKE_CURRENT_LIST_DIR}
    CONFIGURE_DEPENDS
    L*
)
list(LENGTH targets targets_num)
message("Find ${targets_num} targets !")

foreach(target IN LISTS targets)
    set(target_dir ${CMAKE_CURRENT_LIST_DIR}/${target})
    set(target_playground_src ${target_dir}/${target}.cpp)
    set(target_test_src ${target_dir}/Test${target}.cpp)

    if(EXISTS ${target_playground_src})
        add_executable(${target} ${target_playground_src})
        target_link_libraries(${target} PRIVATE leetcode)
    endif()

    if(EXISTS ${target_test_src})
        add_executable(Test${target} ${target_test_src})
        target_link_libraries(Test${target} PRIVATE leetcode catch)
        catch_discover_tests(Test${target})
    endif()
endforeach()


