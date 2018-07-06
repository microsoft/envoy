add_executable(zipkin_test 
span_buffer_test.cc
span_context_test.cc
tracer_test.cc
util_test.cc
zipkin_core_types_test.cc
zipkin_tracer_impl_test.cc
)

target_link_libraries(zipkin_test
    hex_lib
    utility_lib
    conn_manager_lib
    address_lib
    network_utility_lib
    runtime_lib
    zipkin_lib
    test_mocks_common_lib
    http_mocks
    local_info_mocks
    runtime_mocks
    stats_mocks
    thread_local_mocks
    tracing_mocks
    upstream_mocks
    test_common_utility_lib

    test_main

#dependencies
    envoy_all_lib
)
