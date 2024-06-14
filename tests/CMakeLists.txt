# Ajouter les fichiers de test
file(GLOB_RECURSE TEST_SOURCES
    ${PROJECT_SOURCE_DIR}/tests/*.cpp
)
file(GLOB_RECURSE TEST_HEADERS
    ${PROJECT_SOURCE_DIR}/tests/*.h
)

# Ajouter l'exécutable de test
add_executable(SnakeGameTests ${TEST_SOURCES} ${TEST_HEADERS})

# Inclure les répertoires d'en-tête de SFML
include_directories(${sfml_SOURCE_DIR}/include)
include_directories(${googletest_SOURCE_DIR}/googletest/include)
include_directories(${googletest_SOURCE_DIR}/googlemock/include)
include_directories(${PROJECT_SOURCE_DIR}/tests)
include_directories(${PROJECT_SOURCE_DIR}/include/Core)
include_directories(${PROJECT_SOURCE_DIR}/include/Display)
include_directories(${PROJECT_SOURCE_DIR}/include/Entities)
include_directories(${PROJECT_SOURCE_DIR}/include/Interfaces)
include_directories(${PROJECT_SOURCE_DIR}/include/Managers)
include_directories(${PROJECT_SOURCE_DIR}/include/Settings)
include_directories(${PROJECT_SOURCE_DIR}/include/Utils)

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
      gmock_maind.lib
      gtestd.lib
      gmockd.lib
)

target_link_directories(SnakeGameTests PRIVATE ${sfml_BINARY_DIR}/lib)
target_link_directories(SnakeGameTests PRIVATE ${PROJECT_SOURCE_DIR}/bin/lib)

target_link_libraries(SnakeGameTests ${SFML_LIBS})
target_link_libraries(SnakeGameTests ${GOOGLE_TEST_LIBS})

add_custom_command(TARGET SnakeGameTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${PROJECT_SOURCE_DIR}/bin/bin/Debug/gtestd.dll"
            "$<TARGET_FILE_DIR:SnakeGameTests>/gtestd.dll"
       COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${PROJECT_SOURCE_DIR}/bin/bin/Debug/gtest_maind.dll"
            "$<TARGET_FILE_DIR:SnakeGameTests>/gtest_maind.dll"
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${PROJECT_SOURCE_DIR}/bin/bin/Debug/gmockd.dll"
            "$<TARGET_FILE_DIR:SnakeGameTests>/gmockd.dll"
       COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${PROJECT_SOURCE_DIR}/bin/bin/Debug/gmock_maind.dll"
            "$<TARGET_FILE_DIR:SnakeGameTests>/gmock_maind.dll"
    )
