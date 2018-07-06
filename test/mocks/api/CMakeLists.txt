add_library(api_mocks mocks.cc)

target_link_libraries(api_mocks
    os_sys_calls_impl
    filesystem_mocks
)