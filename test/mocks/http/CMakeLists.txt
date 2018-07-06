add_library(http_mocks mocks.cc)

target_link_libraries(http_mocks
    event_mocks
    request_info_mocks
    router_mocks
    tracing_mocks
    host_mocks
    printers_lib
)