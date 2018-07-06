add_library(filesystem_mocks mocks.cc)

target_link_libraries(filesystem_mocks
    thread_lib
)

target_link_libraries(filesystem_mocks
    debug gmockd.lib
)

target_link_libraries(filesystem_mocks
    optimized gmock.lib
)
