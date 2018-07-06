add_library(runtime_mocks mocks.cc)

target_link_libraries(runtime_mocks
    test_mocks_common_lib
)