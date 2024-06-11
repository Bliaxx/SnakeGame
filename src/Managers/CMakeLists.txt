file(GLOB_RECURSE MANAGERS_SOURCES "*.cpp")

add_library(Managers ${MANAGERS_SOURCES})

target_link_libraries(Managers sfml-system sfml-window sfml-graphics sfml-audio)
