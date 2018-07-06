add_executable(manager_impl_test manager_impl_test.cc)
target_link_libraries(manager_impl_test
    singleton_manager_lib
    test_main

#dependencies
    envoy_all_lib
)