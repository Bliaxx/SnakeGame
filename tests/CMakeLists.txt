# Ajout de l'exécutable de test
add_executable(SnakeGameTests TestMain.cpp)

# Lien vers les bibliothèques nécessaires
target_link_libraries(SnakeGameTests sfml-graphics-d sfml-window-d sfml-system-d gtest gtest_main)

# Ajout des tests
include(GoogleTest)
gtest_discover_tests(SnakeGameTests)
