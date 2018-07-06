add_executable(grpc_async_client_impl_test async_client_impl_test.cc)
target_link_libraries(grpc_async_client_impl_test
    async_client_lib
    http_mocks
    tracing_mocks
    upstream_mocks
    helloworld_lib
    
    test_main

#dependencies
    envoy_all_lib
)

add_executable(async_client_manager_impl_test async_client_manager_impl_test.cc)
target_link_libraries(async_client_manager_impl_test
    common_grpc_async_client_manager_lib
    stats_mocks
    thread_local_mocks
    upstream_mocks
    test_common_utility_lib

    test_main

#dependencies
    envoy_all_lib
)

add_executable(codec_test codec_test.cc)
target_link_libraries(codec_test
    buffer_lib
    codec_lib
    helloworld_lib

    test_main

#dependencies
    envoy_all_lib
)

add_executable(common_test common_test.cc)
target_link_libraries(common_test
    common_lib
    upstream_mocks
    helloworld_lib
    test_common_utility_lib

    test_main

#dependencies
    envoy_all_lib
)

add_library(grpc_client_integration_lib INTERFACE)
target_link_libraries(grpc_client_integration_lib INTERFACE
    test_common_utility_lib
)

add_executable(grpc_client_integration_test grpc_client_integration_test.cc)
target_link_libraries(grpc_client_integration_test
    grpc_client_integration_lib
    dispatcher_lib
    async_client_lib
    http2_conn_pool_lib
    connection_lib
    common_network_raw_buffer_socket_lib
    stats_lib
    integration_lib
    grpc_mocks
    http_mocks
    local_info_mocks
    router_mocks
    runtime_mocks
    tracing_mocks
    upstream_mocks
    helloworld_lib
    environment_lib

    test_main

#dependencies
    envoy_all_lib
)

add_executable(http1_bridge_filter_test http1_bridge_filter_test.cc)
target_link_libraries(http1_bridge_filter_test
    buffer_lib
    http1_bridge_filter_lib
    header_map_lib
    http_mocks
    upstream_mocks
    test_common_utility_lib

    test_main

#dependencies
    envoy_all_lib
)

add_executable(google_grpc_test google_grpc_test.cc)
target_link_libraries(google_grpc_test
    test_main

#dependencies
    envoy_all_lib
    gpr.lib
    grpc.lib
    grpc++.lib

    ssl.lib
    crypto.lib
    decrepit.lib
    cares.lib
)
target_link_libraries(google_grpc_test
    debug zlibd.lib
)
target_link_libraries(google_grpc_test
    optimized zlib.lib
)

add_executable(grpc_web_filter_test grpc_web_filter_test.cc)
target_link_libraries(grpc_web_filter_test
    grpc_web_filter_lib
    http_mocks
    upstream_mocks
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)

file(COPY ${PROJECT_SOURCE_DIR}/test/proto/bookstore.proto DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#file(COPY bookstore_proto_descriptor DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

#source not compiled for windows
#add_executable(json_transcoder_filter_test json_transcoder_filter_test.cc)
#source not compiled for windows
#add_executable(transcoder_input_stream_test transcoder_input_stream_test.cc)
