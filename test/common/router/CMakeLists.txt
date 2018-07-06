#include(GoogleTest)

add_executable(config_impl_test config_impl_test.cc)
target_link_libraries(config_impl_test
    metadata_lib
    rds_json_lib
    header_map_lib
    json_loader_lib
    config_utility_lib_router
    runtime_mocks
    upstream_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

add_executable(rds_impl_test rds_impl_test.cc)
target_link_libraries(rds_impl_test
    filter_json_lib
    config_utility_lib
    message_lib
    json_loader_lib
    rds_lib
    admin_lib
    init_mocks
    local_info_mocks
    server_mocks
    thread_local_mocks
    upstream_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

add_executable(retry_state_impl_test retry_state_impl_test.cc)
target_link_libraries(retry_state_impl_test
    header_map_lib
    retry_state_lib
    router_mocks
    runtime_mocks
    upstream_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

add_executable(router_ratelimit_test router_ratelimit_test.cc)
target_link_libraries(router_ratelimit_test
    header_map_lib
    json_loader_lib
    config_utility_lib_router
    router_ratelimit_lib
    http_mocks
    ratelimit_mocks
    router_mocks
    upstream_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

add_executable(router_test router_test.cc)
target_link_libraries(router_test
    buffer_lib
    network_utility_lib
    router_lib
    upstream_lib
    common_lib
    http_mocks
    local_info_mocks
    network_mocks
    router_mocks
    runtime_mocks
    ssl_mocks
    upstream_mocks
    http_common_lib
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

add_executable(router_upstream_log_test router_upstream_log_test.cc)
target_link_libraries(router_upstream_log_test
    buffer_lib
    filter_json_lib
    network_utility_lib
    router_lib
    upstream_lib
    file_access_log_lib
    common_lib
    access_log_mocks
    filesystem_mocks
    http_mocks
    local_info_mocks
    network_mocks
    router_mocks
    runtime_mocks
    server_mocks
    ssl_mocks
    upstream_mocks
    http_common_lib
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

add_executable(shadow_writer_impl_test shadow_writer_impl_test.cc)
target_link_libraries(shadow_writer_impl_test
    message_lib
    shadow_writer_lib
    upstream_mocks
    test_main

#dependencies
    envoy_all_lib
)

add_executable(header_formatter_test header_formatter_test.cc)
target_link_libraries(header_formatter_test
    metadata_lib
    rds_json_lib
    common_router_header_formatter_lib
    common_router_header_parser_lib
    http_mocks
    upstream_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)
