# Ajouter les fichiers de test
file(GLOB_RECURSE TEST_SOURCES
    ${PROJECT_SOURCE_DIR}/tests/*.cpp
)

# Ajouter l'exécutable de test
add_executable(SnakeGameTests ${TEST_SOURCES})

# Inclure les répertoires d'en-tête de SFML
include_directories(${sfml_SOURCE_DIR}/include)
include_directories(${googletest_SOURCE_DIR}/googletest/include)

# Lier les bibliothèques nécessaires
if(WIN32)
    set(SFML_LIBS
        sfml-graphics-d.lib
        sfml-window-d.lib
        sfml-system-d.lib
    )
else()
    set(SFML_LIBS
        libsfml-graphics.so
        libsfml-window.so
        libsfml-system.so
    )
endif()

set(GOOGLE_TEST_LIBS
      gtest_maind.lib
      gtestd.lib
)

target_link_directories(SnakeGameTests PRIVATE ${sfml_BINARY_DIR}/lib)
target_link_directories(SnakeGameTests PRIVATE ${PROJECT_SOURCE_DIR}/bin/lib)

target_link_libraries(SnakeGameTests ${SFML_LIBS})
target_link_libraries(SnakeGameTests ${GOOGLE_TEST_LIBS})
