add_executable(filesystem_subscription_impl_test filesystem_subscription_impl_test.cc)
target_link_libraries(filesystem_subscription_impl_test
    filesystem_subscription_test_harness
    test_main
)

target_link_libraries(filesystem_subscription_impl_test
    debug gtestd.lib
)

target_link_libraries(filesystem_subscription_impl_test
    optimized gtest.lib
)

add_library(filesystem_subscription_test_harness INTERFACE)
target_link_libraries(filesystem_subscription_test_harness INTERFACE
    utility_lib
    dispatcher_lib
    config_mocks
    environment_lib
    test_common_utility_lib   

#dependencies
    logger_lib
    config_utility_lib
    utility_lib_protobuf
    json_loader_lib
    config_schemas_lib
    filesystem_lib
    os_sys_calls_impl
    thread_lib
    buffer_lib
    logger_lib
    libevent_lib
    watcher_lib
    connection_lib
    dns_lib
    listener_lib
    connection_lib_ssl
    address_lib
    listen_socket_lib
    context_lib
    hex_lib
    common_ssl_ssl_socket_lib
    filter_manager_lib
    watermark_buffer_lib
    stats_lib
    version_lib
    stats_mocks

    cares.lib
    fmt.lib
    event.lib
    event_core.lib
    event_extra.lib
    ws2_32.lib
    xxhash.lib

    crypto.lib
    decrepit.lib
    ssl.lib
)

target_link_libraries(filesystem_subscription_test_harness INTERFACE
    debug absl_based.lib
    debug absl_stringsd.lib
    debug gmockd.lib
)

target_link_libraries(filesystem_subscription_test_harness INTERFACE
    optimized absl_based.lib
    optimized absl_stringsd.lib
    optimized gmock.lib
)
