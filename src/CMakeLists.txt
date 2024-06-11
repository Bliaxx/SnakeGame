file(GLOB_RECURSE SOURCES "*.cpp")

add_library(SnakeGameLib ${SOURCES})

target_link_libraries(SnakeGameLib sfml-system sfml-window sfml-graphics sfml-audio)
