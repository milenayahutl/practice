cmake_minimum_required(VERSION 3.23)

set(project "ToDoList")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "C:\Users\Milen\OneDrive\Документы\SFML-3.0.0\lib\cmake\SFML")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

set(${project}_SOURCES
        main.cpp
        todo.cpp)

set(${project}_HEADERS
        todo.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} sfml-graphics sfml-window sfml-system)
