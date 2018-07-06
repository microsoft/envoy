add_executable(buffer_filter_test buffer_filter_test.cc)
target_link_libraries(buffer_filter_test
    header_map_lib
    buffer_filter_lib
    stats_lib
    buffer_mocks
    http_mocks
    upstream_mocks
    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(buffer_filter_test 
    debug gtestd.lib
)

target_link_libraries(buffer_filter_test
    optimized gtest.lib
)

# TODO-WIN cors_filter not compiled for Windows.
#add_executable(cors_filter_test cors_filter_test.cc)

add_executable(fault_filter_test fault_filter_test.cc)
target_link_libraries(fault_filter_test
    buffer_lib
    filter_json_lib
    header_map_lib
    fault_filter_lib
    stats_lib
    common_lib
    http_mocks
    runtime_mocks
    upstream_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(fault_filter_test 
    debug gtestd.lib
)

target_link_libraries(fault_filter_test
    optimized gtest.lib
)

add_executable(ip_tagging_filter_test ip_tagging_filter_test.cc)
target_link_libraries(ip_tagging_filter_test
    buffer_lib
    filter_json_lib
    header_map_lib
    fault_filter_lib
    stats_lib
    common_lib
    http_mocks
    runtime_mocks
    upstream_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(ip_tagging_filter_test 
    debug gtestd.lib
)

target_link_libraries(ip_tagging_filter_test 
    optimized gtest.lib
)

add_executable(ratelimit_test ratelimit_test.cc)
target_link_libraries(ratelimit_test
    buffer_lib
    filter_json_lib
    ratelimit_lib
    http_ratelimit_lib
    fault_filter_lib
    http_mocks
    runtime_mocks
    ratelimit_mocks
    tracing_mocks
    upstream_mocks
    local_info_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

target_link_libraries(ratelimit_test 
    debug gtestd.lib
)

target_link_libraries(ratelimit_test 
    optimized gtest.lib
)

#TODO-WIN. lua source not compiled for windows
#add_subdirectory(lua)