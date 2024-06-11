file(GLOB_RECURSE UTILS_SOURCES "*.cpp")

add_library(Utils ${UTILS_SOURCES})

target_link_libraries(Utils sfml-system sfml-window sfml-graphics sfml-audio)
