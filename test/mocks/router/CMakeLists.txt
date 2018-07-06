add_library(router_mocks mocks.cc)

target_link_libraries(router_mocks
    test_mocks_common_lib
)