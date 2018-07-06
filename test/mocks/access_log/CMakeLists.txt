add_library(access_log_mocks mocks.cc)

target_link_libraries(access_log_mocks
    filesystem_mocks
)