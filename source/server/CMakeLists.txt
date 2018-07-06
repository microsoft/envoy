project(server)

include_directories(${CMAKE_BINARY_DIR}/source)

add_library(configuration_lib configuration_impl.cc)
target_link_libraries(configuration_lib PUBLIC ratelimit_lib_proto)

add_library(connection_handler_lib connection_handler_impl.cc)

add_library(drain_manager_lib drain_manager_impl.cc)

add_library(guarddog_lib guarddog_impl.cc)

add_library(init_manager_lib init_manager_impl.cc)

add_library(options_lib options_impl.cc)

add_library(lds_subscription_lib lds_subscription.cc)

add_library(lds_api_lib lds_api.cc)
target_link_libraries(lds_api_lib PUBLIC lds_subscription_lib)

add_library(listener_manager_lib listener_manager_impl.cc)

add_library(server_lib server.cc)
target_link_libraries(server_lib PUBLIC 
    bootstrap_json_lib
    access_log_manager_lib
)

add_library(watchdog_lib watchdog_impl.cc)

add_library(worker_lib worker_impl.cc)

add_subdirectory(config/access_log)
add_subdirectory(config/http)
add_subdirectory(config/network)
add_subdirectory(config_validation)
add_subdirectory(http)
