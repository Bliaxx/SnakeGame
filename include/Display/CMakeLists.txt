file(GLOB_RECURSE DISPLAY_HEADERS "*.h")

add_library(DisplayHeaders INTERFACE ${DISPLAY_HEADERS})

target_include_directories(DisplayHeaders INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
