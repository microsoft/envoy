add_library(local_info_mocks mocks.cc)

target_link_libraries(local_info_mocks
    address_lib
)