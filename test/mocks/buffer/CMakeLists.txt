add_library(buffer_mocks mocks.cc)

target_link_libraries(buffer_mocks
    test_common_utility_lib
)