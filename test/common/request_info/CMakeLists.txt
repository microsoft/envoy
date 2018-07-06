#include(GoogleTest)

add_executable(request_info_impl_test request_info_impl_test.cc)
target_link_libraries(request_info_impl_test
    router_mocks
    upstream_mocks
    test_main

#dependencies
    envoy_all_lib
)

add_executable(request_info_utility_test utility_test.cc)
target_link_libraries(request_info_utility_test
    common_request_info_utility
    request_info_mocks
    test_main

#dependencies
    envoy_all_lib
)