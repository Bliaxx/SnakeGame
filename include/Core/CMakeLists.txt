file(GLOB_RECURSE HEADERS "*.h")

add_library(CoreHeaders INTERFACE ${HEADERS})

target_include_directories(CoreHeaders INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
