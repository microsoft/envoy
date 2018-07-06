add_library(network_mocks mocks.cc)

target_link_libraries(network_mocks
    address_lib
    network_utility_lib
    event_mocks
    ws2_32.lib
)