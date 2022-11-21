# CMakeList.txt: Projekt CMake pro Projekt, sem přidejte logiku zdrojového
# kódu a definic specifickou pro projekt.
#

# Přidejte zdrojový kód ke spustitelnému souboru tohoto projektu.
add_executable (Projekt "Projekt.cpp" "Projekt.h" "funkce.cpp")
if(WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/include)
endif(WIN32)

# Install dirent.h
if(WIN32)
    install(FILES include/dirent.h DESTINATION include)
endif(WIN32)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Projekt PROPERTY CXX_STANDARD 20)
endif()

# TODO: V případě potřeby přidejte testy a cíle instalace.
