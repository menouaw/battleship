//
// Created by menou on 25/09/2025.
//

#ifndef BATTLESHIP_BASES_H
#define BATTLESHIP_BASES_H

typedef struct Board
{
    int size;
    char ** board;
} Board;

typedef struct Position
{
    int row, col;
} Position;

typedef struct Player
{
    int id;
    Board board;
} Player;

#endif //BATTLESHIP_BASES_H