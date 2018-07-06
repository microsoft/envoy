add_library(request_info_mocks mocks.cc)

target_link_libraries(request_info_mocks
    host_mocks
)