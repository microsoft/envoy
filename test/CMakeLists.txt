include_directories(${PROJECT_SOURCE_DIR})

add_library(test_main main.cc)
target_link_libraries(test_main 
    thread_lib
    libevent_lib
    environment_lib
    printers_lib
    version_lib
    test_common_utility_lib
)

target_link_libraries(test_main
    debug gmockd.lib
    debug gtestd.lib
)

target_link_libraries(test_main
    optimized gmock.lib
    optimized gtest.lib
)

add_subdirectory(common)
add_subdirectory(test_common)
add_subdirectory(mocks)
#add_subdirectory(proto)
#add_subdirectory(integration)