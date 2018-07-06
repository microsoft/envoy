add_executable(ssl_socket_test ssl_socket_test.cc)
target_link_libraries(ssl_socket_test
    buffer_lib
    dispatcher_lib
    json_loader_lib
    listen_socket_lib
    utility_lib
    context_config_lib
    context_lib
    common_ssl_ssl_socket_lib
    stats_lib
    buffer_mocks
    network_mocks
    runtime_mocks
    server_mocks
    stats_mocks
    environment_lib
    network_utility_lib
    test_main

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

target_link_libraries(ssl_socket_test
    debug gtestd.lib
)

target_link_libraries(ssl_socket_test
    optimized gtest.lib
)

file(COPY test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY gen_unittest_certs.bat DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(context_impl_test context_impl_test.cc)
target_link_libraries(context_impl_test
    json_loader_lib
    context_config_lib
    context_lib
    stats_lib
    runtime_mocks
    environment_lib
    test_main

#dependencies
    network_utility_lib
    server_mocks
    stats_mocks
    buffer_mocks
    network_mocks
    common_ssl_ssl_socket_lib
    listen_socket_lib
    utility_lib
    dispatcher_lib
    buffer_lib
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

target_link_libraries(context_impl_test
    debug gtestd.lib
)

target_link_libraries(context_impl_test
    optimized gtest.lib
)
