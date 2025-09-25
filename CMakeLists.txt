cmake_minimum_required(VERSION 4.0)
project(battleship C)

set(CMAKE_C_STANDARD 11)

add_executable(battleship src/main.c
        include/Game/map.h
        src/Game/map.c
        include/DataStructures/bases.h
        src/DataStructures/bases.c
        src/Game/ship.c
        include/Game/ship.h)
