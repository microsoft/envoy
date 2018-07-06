add_executable(dispatcher_impl_test dispatcher_impl_test.cc)
target_link_libraries(dispatcher_impl_test
    dispatcher_lib
    test_mocks_common_lib
    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(dispatcher_impl_test 
    debug gtestd.lib
)

target_link_libraries(dispatcher_impl_test
    optimized gtest.lib
)

add_executable(file_event_impl_test file_event_impl_test.cc)
target_link_libraries(file_event_impl_test
    dispatcher_lib
    test_mocks_common_lib
    environment_lib

    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(file_event_impl_test
    debug gtestd.lib
)

target_link_libraries(file_event_impl_test
    optimized gtest.lib
)

add_executable(dispatched_thread_impl_test dispatched_thread_impl_test.cc)
target_link_libraries(dispatched_thread_impl_test
    utility_lib
    dispatched_thread_lib
    guarddog_lib
    test_mocks_common_lib
    server_mocks
    stats_mocks
    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(dispatched_thread_impl_test
    debug gtestd.lib
)

target_link_libraries(dispatched_thread_impl_test
    optimized gtest.lib
)