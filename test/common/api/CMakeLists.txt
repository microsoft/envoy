add_executable(api_impl_test api_impl_test.cc)
target_link_libraries(api_impl_test
    api_lib
    environment_lib

#dependencies
    dispatcher_lib
    watcher_lib
    connection_lib
    dns_lib
    listener_lib
    connection_lib_ssl
    logger_lib
    utility_lib
    address_lib
    listen_socket_lib
    libevent_lib
    context_lib
    hex_lib
    common_ssl_ssl_socket_lib
    test_common_utility_lib
    config_schemas_lib
    config_utility_lib
    stats_lib
    well_known_names_lib
    filter_manager_lib
    os_sys_calls_impl
    buffer_lib
    thread_lib
    version_lib
    json_loader_lib
    watermark_buffer_lib
    xxhash.lib
    event.lib
    event_core.lib
    event_extra.lib
    cares.lib
    crypto.lib
    decrepit.lib
    ssl.lib

    test_main
)

#dependencies
target_link_libraries(api_impl_test 
    debug libyaml-cppmdd.lib
    optimized libyaml-cppmd.lib
)

#dependencies
target_link_libraries(api_impl_test 
    optimized absl_base.lib
    optimized absl_strings.lib
)

target_link_libraries(api_impl_test
    debug gtestd.lib
    debug gmockd.lib
)

target_link_libraries(api_impl_test
    optimized gtest.lib
    optimized gmock.lib
)