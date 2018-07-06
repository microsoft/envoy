#include(GoogleTest)

add_executable(address_impl_test address_impl_test.cc)
target_link_libraries(address_impl_test
    address_lib
    network_utility_lib
    environment_lib
    test_network_utility_lib
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(address_impl_test 
    debug gtestd.lib
)

target_link_libraries(address_impl_test
    optimized gtest.lib
)

add_executable(cidr_range_test cidr_range_test.cc)
target_link_libraries(cidr_range_test
    address_lib
    cidr_range_lib
    json_loader_lib
    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(cidr_range_test
    debug gtestd.lib
    debug absl_based.lib
    debug absl_stringsd.lib

)

target_link_libraries(cidr_range_test
    optimized gtest.lib
    optimized absl_base.lib
    optimized absl_strings.lib
)

add_executable(connection_impl_test connection_impl_test.cc)
target_link_libraries(connection_impl_test
    buffer_lib
    dispatcher_lib
    connection_lib
    listen_socket_lib
    network_utility_lib
    stats_lib

    buffer_mocks
    event_mocks
    network_mocks
    server_mocks
    stats_mocks
    environment_lib
    test_network_utility_lib
    test_main

#dependencies
    utility_lib
    logger_lib
    libevent_lib
    watcher_lib
    connection_lib
    dns_lib
    listener_lib
    connection_lib_ssl
    listen_socket_lib
    address_lib
    context_lib
    hex_lib
    filter_manager_lib
    common_ssl_ssl_socket_lib
    fmt.lib
    event.lib
    event_core.lib
    event_extra.lib
    ws2_32.lib
    cares.lib
    envoy_all_lib
)

target_link_libraries(connection_impl_test
    debug gtestd.lib
)

target_link_libraries(connection_impl_test
    optimized gtest.lib
)

add_executable(dns_impl_test dns_impl_test.cc)
target_link_libraries(dns_impl_test
    buffer_lib
    dispatcher_lib
    dns_lib
    listen_socket_lib
    network_utility_lib
    stats_lib

    network_mocks
    environment_lib
    test_network_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(dns_impl_test
    debug gtestd.lib
)

target_link_libraries(dns_impl_test
    optimized gtest.lib
)

add_executable(filter_manager_impl_test filter_manager_impl_test.cc)
target_link_libraries(filter_manager_impl_test
    buffer_lib
    filter_json_lib
    ratelimit_lib
    dispatcher_lib
    ratelimit_lib_filter
    tcp_proxy_lib
    filter_manager_lib
    stats_lib

    upstream_lib
    upstream_utility_lib
    buffer_mocks
    network_mocks
    ratelimit_mocks
    runtime_mocks
    server_mocks
    tracing_mocks
    host_mocks
    upstream_mocks
    logger_lib

    test_main

#dependencies
    access_log_lib
    uuid_util_lib
    utility_lib
    http_tracer_lib
    fmt.lib
    crypto.lib
    decrepit.lib
    ssl.lib
    envoy_all_lib
)

target_link_libraries(filter_manager_impl_test
    debug gtestd.lib
)

target_link_libraries(filter_manager_impl_test
    optimized gtest.lib
)

add_executable(listen_socket_impl_test listen_socket_impl_test.cc)
target_link_libraries(listen_socket_impl_test
    listen_socket_lib
    network_utility_lib
    environment_lib
    test_network_utility_lib
    test_main

#dependencies
    utility_lib
    config_utility_lib
    listen_socket_lib
    fmt.lib
    logger_lib
    config_schemas_lib
    envoy_all_lib
)

target_link_libraries(listen_socket_impl_test
    debug gtestd.lib
)

target_link_libraries(listen_socket_impl_test
    optimized gtest.lib
)

add_executable(listener_impl_test listener_impl_test.cc)
target_link_libraries(listener_impl_test
    dispatcher_lib
    address_lib
    listener_lib
    utility_lib
    stats_lib
    network_mocks
    server_mocks
    network_utility_lib
    environment_lib
    test_main

#dependencies
    watcher_lib
    connection_lib
    dns_lib
    listener_lib
    connection_lib_ssl
    common_ssl_ssl_socket_lib
    context_lib
    hex_lib
    logger_lib
    filter_manager_lib
    common_ssl_ssl_socket_lib
    envoy_all_lib
    utility_lib
    fmt.lib
    crypto.lib
    decrepit.lib
    ssl.lib
    cares.lib
)

target_link_libraries(listener_impl_test
    debug gtestd.lib
)

target_link_libraries(listener_impl_test
    optimized gtest.lib
)

add_executable(proxy_protocol_test proxy_protocol_test.cc)
target_link_libraries(proxy_protocol_test
    buffer_lib
    dispatcher_lib
    listener_lib
    utility_lib
    stats_lib
    connection_handler_lib
    buffer_mocks
    network_mocks
    server_mocks

    network_utility_lib
    environment_lib
    test_main

#dependencies
    utility_lib
    watcher_lib
    connection_lib
    dns_lib
    listener_lib
    connection_lib_ssl
    common_ssl_ssl_socket_lib
    context_lib
    hex_lib
    fmt.lib
    envoy_all_lib
)

target_link_libraries(proxy_protocol_test
    debug gtestd.lib
)

target_link_libraries(proxy_protocol_test
    optimized gtest.lib
)

add_executable(resolver_test resolver_impl_test.cc)
target_link_libraries(resolver_test
    address_lib
    resolver_impl_lib
    network_mocks
    
    environment_lib
    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(resolver_test
    debug gtestd.lib
)

target_link_libraries(resolver_test
    optimized gtest.lib
)

add_executable(network_utility_test utility_test.cc)
target_link_libraries(network_utility_test
    address_lib
    utility_lib
    environment_lib
    test_main

#dependencies
    logger_lib
    utility_lib
    fmt.lib
    envoy_all_lib
)

target_link_libraries(network_utility_test
    debug gtestd.lib
)

target_link_libraries(network_utility_test
    optimized gtest.lib
)