file(GLOB_RECURSE DISPLAY_SOURCES "*.cpp")

add_library(Display ${DISPLAY_SOURCES})

target_link_libraries(Display sfml-system sfml-window sfml-graphics sfml-audio)
