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

# Ajout de l'exécutable principal
add_executable(SnakeGame ${SOURCES} ${HEADERS})

# Lier les bibliothèques SFML
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

target_link_libraries(SnakeGame ${SFML_LIBS})

# Copier les actifs (fonts) dans le répertoire de build
add_custom_command(TARGET SnakeGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
        "$<TARGET_FILE_DIR:SnakeGame>/../assets/fonts"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/assets/fonts/arial.ttf"
        "$<TARGET_FILE_DIR:SnakeGame>/../assets/fonts/arial.ttf"
)

# Copier automatiquement les fichiers DLL de SFML dans le répertoire de build
if(WIN32 AND CMAKE_BUILD_TYPE MATCHES Debug)
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
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${sfml_BINARY_DIR}/lib/Debug/sfml-audio-d-2.dll"
            "$<TARGET_FILE_DIR:SnakeGame>/sfml-audio-d-2.dll"
    )
endif()
