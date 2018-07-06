add_library(server_mocks mocks.cc)

target_link_libraries(server_mocks
    singleton_manager_lib
    context_lib
    stats_lib
    access_log_mocks
    api_mocks
    http_mocks
    init_mocks
    local_info_mocks
    network_mocks
    router_mocks
    runtime_mocks
    thread_local_mocks
    tracing_mocks
    upstream_mocks
)