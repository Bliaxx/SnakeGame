file(GLOB RECURSE UTILS_HEADERS "*.h")

add_library(UtilsHeaders INTERFACE ${UTILS_HEADERS})

target_include_directories(UtilsHeaders INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
