file(GLOB RECURSE MANAGERS_HEADERS "*.h")

add_library(ManagersHeaders INTERFACE ${MANAGERS_HEADERS})

target_include_directories(ManagersHeaders INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
