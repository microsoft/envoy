add_executable(protobuf_utility_test utility_test.cc)
target_link_libraries(protobuf_utility_test
    utility_lib_protobuf
    environment_lib
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)