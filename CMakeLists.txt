cmake_minimum_required(VERSION 3.30)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

# Récupérer SFML depuis GitHub
FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.5.1
)

FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.11.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# Prévenir GoogleTest de ne pas définir le mode principal (main) en CMake 3.14+
if(CMAKE_VERSION VERSION_GREATER 3.12)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

enable_testing()

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)

set_property(TARGET sfml-audio PROPERTY CXX_STANDARD 14)
set_property(TARGET sfml-audio PROPERTY CXX_STANDARD_REQUIRED ON)
