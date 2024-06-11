file(GLOB RECURSE SETTINGS_HEADERS "*.h")

add_library(SettingsHeaders INTERFACE ${SETTINGS_HEADERS})

target_include_directories(SettingsHeaders INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
