add_library(init_mocks mocks.cc)

target_link_libraries(init_mocks
    test_mocks_common_lib
)