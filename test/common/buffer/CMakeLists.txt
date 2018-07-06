add_executable(owned_impl_test owned_impl_test.cc)
target_link_libraries(owned_impl_test
    buffer_lib

#dependencies
    libevent_lib
    logger_lib
    event.lib
    event_core.lib
    event_extra.lib
    ws2_32.lib
    fmt.lib

    config_schemas_lib
    config_utility_lib
    stats_lib
    test_main
)

target_link_libraries(owned_impl_test
    debug gtestd.lib
)

target_link_libraries(owned_impl_test
    optimized gtest.lib
)

add_executable(watermark_buffer_test watermark_buffer_test.cc)
target_link_libraries(watermark_buffer_test
    buffer_lib
    watermark_buffer_lib

#dependencies
    libevent_lib
    logger_lib
    event.lib
    event_core.lib
    event_extra.lib
    ws2_32.lib
    fmt.lib

    stats_lib
    config_schemas_lib
    config_utility_lib
    json_loader_lib
    test_common_utility_lib
    test_main
)

target_link_libraries(watermark_buffer_test
    debug gtestd.lib
    debug gmockd.lib
)

target_link_libraries(watermark_buffer_test
    optimized gtest.lib
    optimized gmockd.lib
)

add_executable(zero_copy_input_stream_test zero_copy_input_stream_test.cc)
target_link_libraries(zero_copy_input_stream_test
    zero_copy_input_stream_lib
    buffer_lib

#dependencies
    libevent_lib
    logger_lib
    event.lib
    event_core.lib
    event_extra.lib
    ws2_32.lib
    fmt.lib

    stats_lib
    config_schemas_lib
    config_utility_lib
    test_main
)

target_link_libraries(zero_copy_input_stream_test
    debug gtestd.lib
)

target_link_libraries(zero_copy_input_stream_test
    optimized gtest.lib
)