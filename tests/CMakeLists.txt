# Ajout des répertoires d'inclusion pour les tests
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/Core)
include_directories(${PROJECT_SOURCE_DIR}/include/Display)
include_directories(${PROJECT_SOURCE_DIR}/include/Entities)
include_directories(${PROJECT_SOURCE_DIR}/include/Interfaces)
include_directories(${PROJECT_SOURCE_DIR}/include/Managers)
include_directories(${PROJECT_SOURCE_DIR}/include/Settings)
include_directories(${PROJECT_SOURCE_DIR}/include/Utils)

# Ajout de l'exécutable de test
add_executable(SnakeGameTests TestMain.cpp)

# Lien vers les bibliothèques nécessaires
target_link_libraries(SnakeGameTests sfml-graphics sfml-window sfml-system gtest gtest_main)

# Ajout des tests
include(GoogleTest)
gtest_discover_tests(SnakeGameTests)
