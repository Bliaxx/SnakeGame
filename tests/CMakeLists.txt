# Ajouter les fichiers de test
file(GLOB_RECURSE TEST_SOURCES
    ${PROJECT_SOURCE_DIR}/tests/*.cpp
)

# Ajouter l'exécutable de test
add_executable(SnakeGameTests ${TEST_SOURCES})

# Inclure les répertoires d'en-tête de SFML
include_directories(${sfml_SOURCE_DIR}/include)

# Lier les bibliothèques nécessaires
if(WIN32)
    set(SFML_LIBS
        ${sfml_BINARY_DIR}/lib/Debug/sfml-graphics-d.lib
        ${sfml_BINARY_DIR}/lib/Debug/sfml-window-d.lib
        ${sfml_BINARY_DIR}/lib/Debug/sfml-system-d.lib
        ${sfml_BINARY_DIR}/lib/Debug/sfml-audio-d.lib
    )
else()
    set(SFML_LIBS
        ${sfml_BINARY_DIR}/lib/libsfml-graphics.so
        ${sfml_BINARY_DIR}/lib/libsfml-window.so
        ${sfml_BINARY_DIR}/lib/libsfml-system.so
        ${sfml_BINARY_DIR}/lib/libsfml-audio.so
    )
endif()

target_link_libraries(SnakeGameTests ${SFML_LIBS})

target_link_libraries(SnakeGameTests gtest gtest_main)
