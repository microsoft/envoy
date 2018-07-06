add_library(cluster_info_mocks cluster_info.cc
    $<TARGET_OBJECTS:config_network_raw_buffer_lib>
)


target_link_libraries(cluster_info_mocks
    upstream_lib
    runtime_mocks
    stats_mocks
    original_dst_cluster_lib
    logical_dns_cluster_lib
    health_checker_lib
    http_utility_lib
    common_lib
    metadata_lib
    outlier_detection_lib
    hex_lib
    message_lib
    thread_lib
    common_network_raw_buffer_socket_lib
    zero_copy_input_stream_lib
    codec_client_lib
    host_utility_lib
    eds_lib
    rest_api_fetcher_lib
    grpc_mux_impl_lib
    config_utility_lib
    sds_subscription_lib
    http2_codec_lib
    http1_codec_lib
    buffer_lib
    watermark_buffer_lib
    utility_lib
    to_lower_table_lib
    codes_lib
    header_map_lib 
    nghttp2.lib
    http_parser.lib
    config_schemas_lib
    resolver_impl_lib
)

add_library(host_mocks host.cc)

target_link_libraries(host_mocks
    cluster_info_mocks
    network_utility_lib
    stats_lib
)

add_library(upstream_mocks mocks.cc)

target_link_libraries(upstream_mocks
    config_mocks
    grpc_mocks
    http_mocks
    runtime_mocks
    stats_mocks
)
