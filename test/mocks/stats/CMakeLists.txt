add_library(stats_mocks mocks.cc)

target_link_libraries(stats_mocks
    test_mocks_common_lib
)
target_link_libraries(stats_mocks
    debug gmockd.lib
)

target_link_libraries(stats_mocks
    optimized gmock.lib
)
