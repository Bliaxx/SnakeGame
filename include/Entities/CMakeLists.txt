file(GLOB_RECURSE ENTITIES_HEADERS "*.h")

add_library(EntitiesHeaders INTERFACE ${ENTITIES_HEADERS})

target_include_directories(EntitiesHeaders INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
