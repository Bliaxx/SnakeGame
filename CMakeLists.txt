cmake_minimum_required(VERSION 3.11)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Chemins d'inclusion
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/Core)
include_directories(${PROJECT_SOURCE_DIR}/include/Display)
include_directories(${PROJECT_SOURCE_DIR}/include/Entities)
include_directories(${PROJECT_SOURCE_DIR}/include/Interfaces)
include_directories(${PROJECT_SOURCE_DIR}/include/Managers)
include_directories(${PROJECT_SOURCE_DIR}/include/Settings)
include_directories(${PROJECT_SOURCE_DIR}/include/Utils)
include_directories(${PROJECT_SOURCE_DIR}/lib/SFML/include)

# Chemins des bibliothèques
link_directories(${PROJECT_SOURCE_DIR}/lib/SFML/lib)

# Téléchargement et configuration de GoogleTest
include(FetchContent)

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
