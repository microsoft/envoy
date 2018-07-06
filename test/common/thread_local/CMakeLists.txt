add_executable(thread_local_impl_test thread_local_impl_test.cc)
target_link_libraries(thread_local_impl_test
    dispatcher_lib
    thread_local_lib
    event_mocks
    test_main

#dependencies
    envoy_all_lib
)