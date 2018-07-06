add_executable(async_client_impl_test async_client_impl_test.cc)
target_link_libraries(async_client_impl_test
    buffer_lib
    async_client_lib
    http_utility_lib
    test_mocks_common_lib
    http_common_lib

    buffer_mocks
    http_mocks
    local_info_mocks
    router_mocks
    runtime_mocks
    stats_mocks
    upstream_mocks

    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(async_client_impl_test 
    debug gtestd.lib
)

target_link_libraries(async_client_impl_test 
    optimized gtest.lib
)

add_executable(codec_client_test codec_client_test.cc)
target_link_libraries(codec_client_test
    buffer_lib
    dispatcher_lib
    codec_client_lib
    network_utility_lib
    upstream_lib
    upstream_utility_lib
    test_mocks_common_lib
    event_mocks
    http_mocks
    network_mocks
    upstream_mocks
    environment_lib
    test_network_utility_lib
    test_common_utility_lib

    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(codec_client_test 
    debug gtestd.lib
)

target_link_libraries(codec_client_test 
    optimized gtest.lib
)

add_executable(codes_test codes_test.cc)
target_link_libraries(codes_test
    codes_lib
    header_map_lib
    stats_lib
    test_common_utility_lib
    stats_mocks
    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(codes_test 
    debug gtestd.lib
)

target_link_libraries(codes_test 
    optimized gtest.lib
)

add_library(http_common_lib common.cc)
target_link_libraries(http_common_lib
    test_mocks_common_lib

#dependencies
)

target_link_libraries(http_common_lib 
    debug gtestd.lib
)

target_link_libraries(http_common_lib 
    optimized gtest.lib
)

add_executable(conn_manager_impl_test conn_manager_impl_test.cc)
target_link_libraries(conn_manager_impl_test
    access_log_formatter_lib
    access_log_lib
    buffer_lib
    dispatcher_lib
    conn_manager_lib
    date_provider_lib
    header_map_lib
    address_lib
    stats_lib
    upstream_lib

    test_mocks_common_lib
    access_log_mocks
    buffer_mocks
    http_mocks
    local_info_mocks
    network_mocks
    runtime_mocks
    ssl_mocks
    tracing_mocks
    upstream_mocks

    test_main

#dependencies
    test_common_utility_lib

#dependencies
    envoy_all_lib
)

target_link_libraries(conn_manager_impl_test 
    debug gtestd.lib
)

target_link_libraries(conn_manager_impl_test 
    optimized gtest.lib
)

add_executable(conn_manager_utility_test conn_manager_utility_test.cc)
target_link_libraries(conn_manager_utility_test
    dispatcher_lib
    conn_manager_lib
    address_lib
    network_utility_lib
    runtime_lib
    uuid_util_lib

    http_mocks
    local_info_mocks
    network_mocks
    runtime_mocks
    ssl_mocks
    upstream_mocks
    test_common_utility_lib

    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(conn_manager_utility_test 
    debug gtestd.lib
)

target_link_libraries(conn_manager_utility_test 
    optimized gtest.lib
)

add_executable(date_provider_impl_test date_provider_impl_test.cc)
target_link_libraries(date_provider_impl_test
    date_provider_lib
    header_map_lib
    event_mocks
    thread_local_mocks

    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(date_provider_impl_test 
    debug gtestd.lib
)

target_link_libraries(date_provider_impl_test 
    optimized gtest.lib
)

add_executable(header_map_impl_test header_map_impl_test.cc)
target_link_libraries(header_map_impl_test
    header_map_lib
    test_common_utility_lib
    
    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(header_map_impl_test 
    debug gtestd.lib
)

target_link_libraries(header_map_impl_test 
    optimized gtest.lib
)

add_executable(user_agent_test user_agent_test.cc)
target_link_libraries(user_agent_test
    header_map_lib
    user_agent_lib
    stats_mocks
    test_common_utility_lib
    
    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(user_agent_test 
    debug gtestd.lib
)

target_link_libraries(user_agent_test 
    optimized gtest.lib
)

add_executable(http_utility_test utility_test.cc)
target_link_libraries(http_utility_test
    header_map_lib
    http_utility_lib
    address_lib

    http_mocks
    upstream_mocks
    test_common_utility_lib
    
    test_main

#dependencies
    logger_lib
    fmt.lib
)

target_link_libraries(http_utility_test 
    debug gtestd.lib
)

target_link_libraries(http_utility_test 
    optimized gtest.lib
)

add_subdirectory(filter)
add_subdirectory(http1)
add_subdirectory(http2)