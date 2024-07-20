cmake_minimum_required(VERSION 3.28)
project(Tetris)

set(CMAKE_CXX_STANDARD 23)

add_link_options(-static -static-libgcc -static-libstdc++)

add_executable(Tetris main.cpp
        Listener.cpp
        Listener.h
        Render.cpp
        Render.h
        Chunk.cpp
        Chunk.h
        Key.cpp
        Key.h
        Player.cpp
        Player.h)
