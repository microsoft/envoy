add_executable(http_tracer_impl_test http_tracer_impl_test.cc)
target_link_libraries(http_tracer_impl_test
    base64_lib
    header_map_lib
    message_lib
    runtime_lib
    uuid_util_lib
    http_tracer_lib
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

add_subdirectory(zipkin)