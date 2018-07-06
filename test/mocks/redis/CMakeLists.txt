add_library(redis_mocks mocks.cc)

target_link_libraries(redis_mocks
    codec_lib
)