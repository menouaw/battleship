cmake_minimum_required(VERSION 4.0)
project(battleship C)

set(CMAKE_C_STANDARD 11)

add_executable(battleship src/main.c
        include/Game/board.h
        src/Game/board.c
        include/DataStructures/bases.h
        src/DataStructures/bases.c
        src/Game/ship.c
        include/Game/ship.h
        src/Game/actions.c
        include/Game/actions.h
        src/Game/checks.c
        include/Game/checks.h)
