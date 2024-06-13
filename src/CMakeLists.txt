# Ajout des fichiers source et des fichiers d'en-tête
file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE HEADERS
    ${PROJECT_SOURCE_DIR}/include/*.h
)

# Ajout de l'exécutable principal
add_executable(SnakeGame ${SOURCES} ${HEADERS})

# Lien vers les bibliothèques nécessaires
target_link_libraries(SnakeGame sfml-graphics-d sfml-window-d sfml-system-d)

# Copier les actifs (fonts) dans le répertoire de build
add_custom_command(TARGET SnakeGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
        "$<TARGET_FILE_DIR:SnakeGame>/../assets/fonts"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/assets/fonts/arial.ttf"
        "$<TARGET_FILE_DIR:SnakeGame>/../assets/fonts/arial.ttf"
)
