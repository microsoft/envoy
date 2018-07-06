#include(GoogleTest)

add_executable(base64_test base64_test.cc)
target_link_libraries(base64_test
    buffer_lib
    base64_lib
    fmt.lib
    logger_lib
    libevent_lib
    event.lib
    event_core.lib
    event_extra.lib
    Ws2_32.lib
)

target_link_libraries(base64_test 
    debug gtestd.lib
    debug gtest_maind.lib
)

target_link_libraries(base64_test 
    optimized gtest.lib
    optimized gtest_main.lib
)

add_executable(hex_test hex_test.cc)
target_link_libraries(hex_test
    hex_lib
    utility_lib
    fmt.lib
)

target_link_libraries(hex_test
    debug absl_based.lib
    debug absl_stringsd.lib
    debug gtestd.lib
    debug gtest_maind.lib
)

target_link_libraries(hex_test
    optimized gtest.lib
    optimized gtest_main.lib 
    optimized absl_base.lib
    optimized absl_strings.lib
)

add_executable(utility_test utility_test.cc)
target_link_libraries(utility_test
    utility_lib
    test_common_utility_lib
)

target_link_libraries(utility_test
    debug gtestd.lib
    debug gtest_maind.lib
)

target_link_libraries(utility_test
    optimized gtest.lib
    optimized gtest_main.lib 
)

add_executable(to_lower_table_test to_lower_table_test.cc)
target_link_libraries(to_lower_table_test
    to_lower_table_lib
)

target_link_libraries(to_lower_table_test
    debug gtestd.lib
    debug gtest_maind.lib
)

target_link_libraries(to_lower_table_test
    optimized gtest.lib
    optimized gtest_main.lib 
)

add_executable(log_macros_test log_macros_test.cc)
target_link_libraries(log_macros_test
    logger_lib
    filesystem_lib
    http_mocks
    network_mocks
    upstream_mocks
    request_info_mocks
    libevent_lib
)

target_link_libraries(log_macros_test
    googleapis.lib
    protoc-gen-validate.lib
    gogoproto.lib
    event.lib
    event_core.lib
    event_extra.lib
)


target_link_libraries(log_macros_test
    debug gtestd.lib
    debug gtest_maind.lib

    debug libprotobufd.lib
    debug libprotocd.lib
)

target_link_libraries(log_macros_test
    optimized gtest.lib
    optimized gtest_main.lib 

    optimized libprotobuf.lib
    optimized libprotoc.lib
)

target_link_libraries(log_macros_test
    data-plane-api.lib
)

#gtest_discover_tests(base64_test)
