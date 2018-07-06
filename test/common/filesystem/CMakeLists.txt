add_executable(filesystem_impl_test filesystem_impl_test.cc)
target_link_libraries(filesystem_impl_test
    os_sys_calls_impl
    thread_lib
    dispatcher_lib
    filesystem_lib
    stats_lib
    api_mocks
    event_mocks
    filesystem_mocks
    environment_lib
    
    test_main

#dependencies
    envoy_all_lib
)

add_executable(watcher_impl_test watcher_impl_test.cc)
target_link_libraries(watcher_impl_test
    dispatcher_lib
    watcher_lib
    environment_lib

    test_main

#dependencies
    envoy_all_lib
)
