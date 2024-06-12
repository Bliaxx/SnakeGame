# Inclure les répertoires de tests
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Ajouter les fichiers de tests
file(GLOB TEST_SOURCES "*.cpp")

add_executable(SnakeGameTests ${TEST_SOURCES})

# Lier GoogleTest et les bibliothèques du projet
target_link_libraries(SnakeGameTests gtest gtest_main sfml-system sfml-window sfml-graphics SnakeGameHeaders)
