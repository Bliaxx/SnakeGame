cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0135 NEW)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)

# Inclure les répertoires d'inclusion
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/lib/SFML/include)

# Ajouter les sous-répertoires
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(lib/SFML)
add_subdirectory(tests)

# Ajouter l'exécutable
add_executable(SnakeGame src/SnakeGame.cpp)

# Lier les bibliothèques SFML directement
target_link_libraries(SnakeGame sfml-system sfml-window sfml-graphics sfml-audio)

# Lier les en-têtes
target_link_libraries(SnakeGame SnakeGameHeaders)

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
add_executable(SnakeGameTestExecutable tests/TestMain.cpp)

# Lier GoogleTest et les bibliothèques du projet
target_link_libraries(SnakeGameTestExecutable gtest gtest_main sfml-system sfml-window sfml-graphics sfml-audio SnakeGameHeaders)
