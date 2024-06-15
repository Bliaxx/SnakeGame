# Ajout des répertoires d'inclusion pour les fichiers source
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/Core)
include_directories(${PROJECT_SOURCE_DIR}/include/Display)
include_directories(${PROJECT_SOURCE_DIR}/include/Entities)
include_directories(${PROJECT_SOURCE_DIR}/include/Interfaces)
include_directories(${PROJECT_SOURCE_DIR}/include/Managers)
include_directories(${PROJECT_SOURCE_DIR}/include/Settings)
include_directories(${PROJECT_SOURCE_DIR}/include/Utils)
include_directories(${sfml_SOURCE_DIR}/include)  # Inclure les en-têtes SFML

# Ajout des fichiers source et des fichiers d'en-tête
file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE HEADERS
    ${PROJECT_SOURCE_DIR}/include/*.h
)

add_library(SnakeGameLib STATIC ${SOURCES} ${HEADERS})

# Ajout de l'exécutable principal
add_executable(SnakeGame ${SOURCES} ${HEADERS})

# Lier les bibliothèques SFML
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

target_link_directories(SnakeGame PRIVATE ${sfml_BINARY_DIR}/lib)

target_link_libraries(SnakeGame ${SFML_LIBS})
target_link_libraries(SnakeGameLib ${SFML_LIBS})

# Copier les actifs (fonts) dans le répertoire de build
add_custom_command(TARGET SnakeGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
        "$<TARGET_FILE_DIR:SnakeGame>/../assets/fonts"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/assets/fonts/arial.ttf"
        "$<TARGET_FILE_DIR:SnakeGame>/../assets/fonts/arial.ttf"
)

add_custom_command(TARGET SnakeGame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${sfml_BINARY_DIR}/lib/Debug/sfml-graphics-d-2.dll"
            "$<TARGET_FILE_DIR:SnakeGame>/sfml-graphics-d-2.dll"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${sfml_BINARY_DIR}/lib/Debug/sfml-window-d-2.dll"
            "$<TARGET_FILE_DIR:SnakeGame>/sfml-window-d-2.dll"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${sfml_BINARY_DIR}/lib/Debug/sfml-system-d-2.dll"
            "$<TARGET_FILE_DIR:SnakeGame>/sfml-system-d-2.dll"
    )
