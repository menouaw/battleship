//
// Created by menou on 25/09/2025.
//
#include "../DataStructures/bases.h"

#define BOARD_SIZE 5;

#ifndef BATTLESHIP_MAP_H
#define BATTLESHIP_MAP_H

void allocate_board(Board * board);

void print_board(const Board * board);

void free_board(Board * board);

#endif //BATTLESHIP_MAP_H