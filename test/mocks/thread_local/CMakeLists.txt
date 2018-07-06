add_library(thread_local_mocks mocks.cc)

target_link_libraries(thread_local_mocks
    event_mocks
)