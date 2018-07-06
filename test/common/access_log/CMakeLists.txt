add_executable(access_log_impl_test access_log_impl_test.cc)
target_link_libraries(access_log_impl_test
    access_log_lib
    filter_json_lib
    utility_lib

    access_log_mocks
    event_mocks
    filesystem_mocks
    runtime_mocks
    server_mocks
    upstream_mocks
    test_common_utility_lib

#dependencies
    logger_lib
    config_utility_lib
    http_utility_lib
    uuid_util_lib
    http_tracer_lib
    well_known_names_lib
    hex_lib
    filesystem_lib
    common_lib
    config_schemas_lib
    utility_lib_protobuf
    stats_lib
    buffer_lib
    message_lib
    header_map_lib
    json_loader_lib
    network_utility_lib
    runtime_lib
    access_log_formatter_lib
    common_request_info_utility
    base64_lib
    zero_copy_input_stream_lib
 
    crypto.lib
    decrepit.lib
    ssl.lib
)

target_link_libraries(access_log_impl_test
    debug gtestd.lib
    debug gtest_maind.lib
)

target_link_libraries(access_log_impl_test
    optimized gtest.lib
    optimized gtest_main.lib
)

add_executable(access_log_formatter_test access_log_formatter_test.cc)
target_link_libraries(access_log_formatter_test
    access_log_formatter_lib
    utility_lib
    logger_lib
    header_map_lib
    common_request_info_utility
    access_log_mocks
    event_mocks
    filesystem_mocks
    runtime_mocks
    server_mocks
    upstream_mocks
    test_common_utility_lib
    test_main
)

target_link_libraries(access_log_formatter_test
    debug gtestd.lib
)

target_link_libraries(access_log_formatter_test
    optimized gtest.lib
)


#source file to be ported to Windows, hence skipping test
#add_executable(grpc_access_log_impl_test grpc_access_log_impl_test.cc)

add_executable(access_log_manager_impl_test access_log_manager_impl_test.cc)
target_link_libraries(access_log_manager_impl_test
    access_log_manager_lib
    stats_lib
    access_log_mocks
    filesystem_mocks
    api_mocks
    event_mocks

#dependencies
    logger_lib
    utility_lib
    well_known_names_lib
    utility_lib_protobuf
    config_schemas_lib
    config_utility_lib
    test_main
)

target_link_libraries(access_log_manager_impl_test
    debug gtestd.lib
)
target_link_libraries(access_log_manager_impl_test
    optimized gtest.lib
)

