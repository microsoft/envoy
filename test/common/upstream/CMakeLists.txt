#include(GoogleTest)

add_library(upstream_utility_lib INTERFACE)
target_link_libraries(upstream_utility_lib INTERFACE
    json_loader_lib
    cds_json_lib
    network_utility_lib
    upstream_lib
)

target_link_libraries(upstream_utility_lib INTERFACE
    debug gtestd.lib
)

target_link_libraries(upstream_utility_lib INTERFACE
    optimized gtest.lib
)

add_executable(cds_api_impl_test cds_api_impl_test.cc)
target_link_libraries(cds_api_impl_test
    config_utility_lib
    message_lib
    json_loader_lib
    cds_api_lib
    local_info_mocks
    upstream_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

add_executable(cluster_manager_impl_test cluster_manager_impl_test.cc)
target_link_libraries(cluster_manager_impl_test
    access_log_mocks
    http_mocks
    local_info_mocks
    network_mocks
    runtime_mocks
    thread_local_mocks
    upstream_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

add_executable(eds_test eds_test.cc)
target_link_libraries(eds_test
    upstream_utility_lib
    local_info_mocks
    runtime_mocks
    ssl_mocks
    thread_local_mocks
    upstream_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

add_executable(health_checker_impl_test health_checker_impl_test.cc)
target_link_libraries(health_checker_impl_test
    upstream_utility_lib
    network_mocks
    redis_mocks
    runtime_mocks
    upstream_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

add_executable(host_utility_test host_utility_test.cc)
target_link_libraries(host_utility_test
    upstream_utility_lib
    upstream_mocks
    test_main

#dependencies
    envoy_all_lib
)

add_executable(load_balancer_impl_test load_balancer_impl_test.cc)
target_link_libraries(load_balancer_impl_test
    upstream_utility_lib
    runtime_mocks
    upstream_mocks
    test_main

#dependencies
    envoy_all_lib
)

add_executable(load_balancer_simulation_test load_balancer_simulation_test.cc)
target_link_libraries(load_balancer_simulation_test
    upstream_utility_lib
    runtime_mocks
    upstream_mocks
    test_main

#dependencies
    envoy_all_lib
)

add_executable(load_stats_reporter_test load_stats_reporter_test.cc)
target_link_libraries(load_stats_reporter_test
    upstream_utility_lib
    event_mocks
    grpc_mocks
    upstream_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

add_executable(logical_dns_cluster_test logical_dns_cluster_test.cc)
target_link_libraries(logical_dns_cluster_test
    upstream_utility_lib
    test_mocks_common_lib
    network_mocks
    runtime_mocks
    ssl_mocks
    thread_local_mocks
    upstream_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

add_executable(original_dst_cluster_test original_dst_cluster_test.cc)
target_link_libraries(original_dst_cluster_test
    upstream_utility_lib
    test_mocks_common_lib
    network_mocks
    runtime_mocks
    ssl_mocks
    upstream_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

add_executable(outlier_detection_impl_test outlier_detection_impl_test.cc)
target_link_libraries(outlier_detection_impl_test
    upstream_utility_lib
    access_log_mocks
    event_mocks
    runtime_mocks
    upstream_mocks
    test_main

#dependencies
    envoy_all_lib
)

add_executable(resource_manager_impl_test resource_manager_impl_test.cc)
target_link_libraries(resource_manager_impl_test
    runtime_mocks
    test_main

#dependencies
    envoy_all_lib
)

add_executable(ring_hash_lb_test ring_hash_lb_test.cc)
target_link_libraries(ring_hash_lb_test
    upstream_utility_lib
    runtime_mocks
    upstream_mocks
    test_main

#dependencies
    envoy_all_lib
)

file(COPY test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(sds_test sds_test.cc)
target_link_libraries(sds_test
    upstream_utility_lib
    local_info_mocks
    runtime_mocks
    ssl_mocks
    upstream_mocks
    environment_lib
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

add_executable(subset_lb_test subset_lb_test.cc)
target_link_libraries(subset_lb_test
    upstream_utility_lib
    runtime_mocks
    upstream_mocks
    test_main

#dependencies
    envoy_all_lib
)

add_executable(upstream_impl_test upstream_impl_test.cc)
target_link_libraries(upstream_impl_test
    upstream_utility_lib
    test_mocks_common_lib
    network_mocks
    runtime_mocks
    ssl_mocks
    upstream_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)