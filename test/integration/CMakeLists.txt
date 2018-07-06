add_library(integration_lib autonomous_upstream.cc
    fake_upstream.cc
    integration.cc
    server.cc
    ssl_utility.cc
    utility.cc
)

target_link_libraries(integration_lib
#dependencies
    envoy_all_lib
)

target_link_libraries(integration_lib
    debug gtestd.lib
)

target_link_libraries(integration_lib
    optimized gtest.lib
)