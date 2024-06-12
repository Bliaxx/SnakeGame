# Include all header files in the include directory and its subdirectories
file(GLOB_RECURSE HEADER_FILES "*.h")

add_library(SnakeGameHeaders INTERFACE ${HEADER_FILES})

target_include_directories(SnakeGameHeaders INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
