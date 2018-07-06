add_executable(ratelimit_impl_test ratelimit_impl_test.cc)
target_link_libraries(ratelimit_impl_test
    header_map_lib
    ratelimit_lib
    grpc_mocks
    upstream_mocks
    test_main

#dependencies
    envoy_all_lib
)