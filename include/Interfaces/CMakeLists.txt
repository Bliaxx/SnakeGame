file(GLOB_RECURSE INTERFACES_HEADERS "*.h")

add_library(InterfacesHeaders INTERFACE ${INTERFACES_HEADERS})

target_include_directories(InterfacesHeaders INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
