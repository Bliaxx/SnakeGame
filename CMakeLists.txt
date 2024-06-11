cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)

# Inclure les répertoires d'inclusion
include_directories(include lib/SFML/include)

# Ajouter les sous-répertoires
add_subdirectory(src)
add_subdirectory(lib/SFML)
add_subdirectory(tests)

# Ajouter l'exécutable
add_executable(SnakeGame src/main.cpp)

# Lier les bibliothèques SFML directement
target_link_libraries(SnakeGame sfml-system sfml-window sfml-graphics sfml-audio)

# Télécharger et configurer GoogleTest
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# Pour les anciennes versions de CMake
if(${CMAKE_VERSION} VERSION_LESS 3.14)
  FetchContent_GetProperties(googletest)
  if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
  endif()
else()
  FetchContent_MakeAvailable(googletest)
endif()

# Activer les tests
enable_testing()

# Ajouter un exécutable pour les tests
add_executable(SnakeGameTests tests/test_main.cpp)

# Lier GoogleTest
target_link_libraries(SnakeGameTests gtest gtest_main)
