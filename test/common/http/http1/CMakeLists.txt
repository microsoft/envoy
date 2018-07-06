add_executable(http1_codec_impl_test codec_impl_test.cc)
target_link_libraries(http1_codec_impl_test
    buffer_lib
    dispatcher_lib
    header_map_lib
    http1_codec_lib
    buffer_mocks
    http_mocks
    network_mocks
    upstream_mocks
    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(http1_codec_impl_test 
    debug gtestd.lib
)

target_link_libraries(http1_codec_impl_test
    optimized gtest.lib
)

add_executable(http1_conn_pool_test conn_pool_test.cc)
target_link_libraries(http1_conn_pool_test
    buffer_lib
    dispatcher_lib
    http1_conn_pool_lib
    network_utility_lib
    upstream_lib
    upstream_utility_lib
    common_lib
    buffer_mocks
    event_mocks
    http_mocks
    network_mocks
    runtime_mocks
    upstream_mocks
    test_common_utility_lib

    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(http1_conn_pool_test 
    debug gtestd.lib
)

target_link_libraries(http1_conn_pool_test
    optimized gtest.lib
)