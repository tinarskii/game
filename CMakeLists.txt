cmake_minimum_required(VERSION 3.16)

project(my_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib 3.0 REQUIRED)

add_executable(
    my_game 
        src/Main.cpp
        src/SceneManager.cpp
        src/SceneManager.hpp
        src/Character.cpp
        src/Character.hpp
        src/raygui.h
)
target_link_libraries(my_game raylib)