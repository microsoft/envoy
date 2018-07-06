set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_library(environment_lib environment.cc)

target_link_libraries(environment_lib PUBLIC 
    network_utility_lib
    utility_lib
    options_lib
    test_network_utility_lib
    ws2_32.lib
)

target_link_libraries(environment_lib PUBLIC 
    debug absl_based.lib
    debug absl_stringsd.lib
)

target_link_libraries(environment_lib PUBLIC 
    optimized absl_base.lib
    optimized absl_strings.lib
)

add_library(test_network_utility_lib network_utility.cc)
target_link_libraries(test_network_utility_lib PUBLIC 
    address_lib
    common_network_raw_buffer_socket_lib
    utility_lib
    runtime_lib
)

add_library(printers_lib printers.cc)
target_link_libraries(printers_lib PUBLIC 
    buffer_lib
    header_map_lib
    codec_lib
)

add_library(test_common_utility_lib utility.cc)
target_link_libraries(test_common_utility_lib  PUBLIC
    utility_lib
    bootstrap_json_lib
    header_map_lib
    json_loader_lib
    network_utility_lib
    address_lib
    utility_lib_protobuf
    well_known_names_lib
    tls_context_json_lib
    filesystem_lib
    os_sys_calls_impl
    buffer_lib
    libevent_lib
    thread_lib
    cidr_range_lib
    protocol_json_lib

    ws2_32.lib
    event.lib
    event_core.lib
    event_extra.lib
    xxhash.lib
    fmt.lib
    gogoproto.lib
    googleapis.lib
    protoc-gen-validate.lib
    health.lib
)
target_link_libraries(test_common_utility_lib PUBLIC
    debug libprotobufd.lib
    debug libprotocd.lib
)
target_link_libraries(test_common_utility_lib PUBLIC
    debug absl_based.lib
    debug absl_stringsd.lib
    debug libyaml-cppmdd.lib
)
target_link_libraries(test_common_utility_lib PUBLIC
    optimized absl_base.lib
    optimized absl_strings.lib
    optimized libyaml-cppmd.lib
)

target_link_libraries(test_common_utility_lib PRIVATE
    data-plane-api.lib
)

add_library(envoy_all_lib INTERFACE)
target_link_libraries(envoy_all_lib INTERFACE 
    envoy_main_common_lib
    config_http_zipkin_lib
    xxhash.lib
    base64_lib
    hex_lib
    logger_lib
    thread_lib
    utility_lib
    version_lib
    to_lower_table_lib
    api_lib
    buffer_lib
    zero_copy_input_stream_lib
    dispatcher_lib
    dispatched_thread_lib
    memory_stats_lib
    statsd_lib
    guarddog_lib
    profiler_lib
    codec_lib
    logger_lib
    thread_local_lib
    server_lib_config_validation
    utility_lib
    configuration_lib
    connection_handler_lib
    init_manager_lib
    lds_api_lib
    listener_manager_lib
    watchdog_lib
    worker_lib
    
    buffer_filter_lib
    config_lib_router
    config_utility_lib_router
    rds_lib
    retry_state_lib
    router_lib
    router_ratelimit_lib
    shadow_writer_lib
    async_client_lib
    codec_client_lib
    codes_lib
    conn_manager_lib
    date_provider_lib
    header_map_lib
    message_lib
    rest_api_fetcher_lib
    user_agent_lib
    http_utility_lib
    filter_utility_lib
    admin_lib
    common_lib
    http_tracer_lib
    zipkin_lib
    access_log_formatter_lib
    http2_codec_lib
    http2_conn_pool_lib
    codec_client_lib
    http1_codec_lib
    http1_conn_pool_lib
    ratelimit_lib
    cds_api_lib
    cluster_manager_lib
    health_checker_lib
    host_utility_lib
    load_balancer_lib
    logical_dns_cluster_lib
    outlier_detection_lib
    ring_hash_lb_lib
    eds_lib
    sds_subscription_lib
    upstream_lib
    protocol_json_lib
    tls_context_json_lib
    api_lib_config_validation
    async_client_lib_config_validation
    cluster_manager_lib_config_validation
    dispatcher_lib_config_validation
    dns_lib_config_validation
    server_lib_config_validation
    watcher_lib
    filesystem_lib
    config_schemas_lib
    json_loader_lib
    metadata_lib
    config_utility_lib
    shadow_writer_lib
    router_ratelimit_lib
    router_lib
    retry_state_lib
    rds_lib
    address_lib
    runtime_lib
    uuid_util_lib
    connection_lib_ssl
    context_config_lib
    context_lib
    watermark_buffer_lib
    buffer_lib
    zero_copy_input_stream_lib
    cidr_range_lib
    connection_lib
    dns_lib
    filter_manager_lib
    listen_socket_lib
    filter_json_lib
    well_known_names_lib
    utility_lib_protobuf
    singleton_manager_lib
    listener_lib
    access_log_lib
    common_html_utility 
    common_request_info_utility
    common_grpc_async_client_manager_lib
    common_ssl_ssl_socket_lib
    common_network_raw_buffer_socket_lib
    fault_filter_lib
    grpc_web_filter_lib
    http1_bridge_filter_lib
    http_ratelimit_lib
    ip_tagging_filter_lib
    ratelimit_lib_filter
    proxy_protocol_lib
    health.lib                
    cares.lib
	event.lib
    event_core.lib
    event_extra.lib
    nghttp2.lib
    Ws2_32.lib
    http_parser.lib
    googleapis.lib
    Rpcrt4.lib
    protoc-gen-validate.lib
    gogoproto.lib
)

target_link_libraries(envoy_all_lib INTERFACE
    debug libprotobufd.lib
    debug libprotocd.lib

    optimized libprotobuf.lib
    optimized libprotoc.lib
)

target_link_libraries(envoy_all_lib INTERFACE
    debug absl_based.lib
    debug absl_stringsd.lib
)

target_link_libraries(envoy_all_lib INTERFACE
    optimized absl_base.lib
    optimized absl_strings.lib
)

target_link_libraries(envoy_all_lib INTERFACE
    crypto.lib
    decrepit.lib
    ssl.lib
)

target_link_libraries(envoy_all_lib INTERFACE
    debug libyaml-cppmdd.lib
    optimized libyaml-cppmd.lib
)


target_link_libraries(envoy_all_lib INTERFACE
    data-plane-api.lib
)
