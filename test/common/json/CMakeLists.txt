add_executable(config_schemas_test config_schemas_test.cc)
target_link_libraries(config_schemas_test
    config_schemas_lib
    json_loader_lib
    environment_lib
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)
file(COPY config_schemas_test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(json_loader_test json_loader_test.cc)
target_link_libraries(json_loader_test
    json_loader_lib
    test_common_utility_lib
    test_main

#dependencies
    envoy_all_lib
)