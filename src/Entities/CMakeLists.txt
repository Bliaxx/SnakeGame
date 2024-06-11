file(GLOB_RECURSE ENTITIES_SOURCES "*.cpp")

add_library(Entities ${ENTITIES_SOURCES})

target_link_libraries(Entities sfml-system sfml-window sfml-graphics sfml-audio)
