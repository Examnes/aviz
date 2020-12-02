cmake_minimum_required(VERSION 3.9)
project(aviz)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)

set(SOURCES src/main.cpp 
            src/menue.cpp
            src/test_logic.cpp
            src/test.cpp 
            src/theory.cpp
            src/graph.cpp
            src/visualization.cpp) 

set(HEADERS inc/menue.h
            inc/test_logic.h 
            inc/test.h 
            inc/theory.h
            inc/graph.h
            inc/visualization.h)

set(UI_FILES    ui/main_menue.ui 
                ui/test.ui 
                ui/theory.ui 
                ui/vis.ui)

set(BINDINGS_QT5 OТ CACHE BOOL "enable BINDINGS_QT5" FORCE)
add_subdirectory(qgv)


qt5_wrap_ui(UI ${UI_FILES})
add_executable(aviz ${SOURCES} ${HEADERS} ${UI})

target_include_directories(aviz PUBLIC qgv)
target_link_libraries(aviz Qt5::Widgets)
target_link_libraries(aviz qgvcore)
set_target_properties(aviz PROPERTIES AUTOGEN_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})

target_include_directories(aviz PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)