add_library(event_mocks mocks.cc)

target_link_libraries(event_mocks
    buffer_mocks
)