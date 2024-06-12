add_library(sfml-graphics STATIC IMPORTED)
add_library(sfml-system STATIC IMPORTED)
add_library(sfml-window STATIC IMPORTED)

set_target_properties(sfml-graphics PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/SFML/lib/sfml-graphics-s.lib)
set_target_properties(sfml-system PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/SFML/lib/sfml-system-s.lib)
set_target_properties(sfml-window PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/SFML/lib/sfml-window-s.lib)
