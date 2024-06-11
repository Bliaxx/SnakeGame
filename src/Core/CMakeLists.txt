file(GLOB_RECURSE CORE_SOURCES "*.cpp")

add_library(Core ${CORE_SOURCES})

target_link_libraries(Core sfml-system sfml-window sfml-graphics sfml-audio)
