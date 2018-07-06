add_executable(html_utility_test utility_test.cc)
target_link_libraries(html_utility_test
    common_html_utility
    test_main

#dependencies
    envoy_all_lib
)