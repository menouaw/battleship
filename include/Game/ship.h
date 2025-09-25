//
// Created by menou on 25/09/2025.
//
#include "../DataStructures/bases.h"

#ifndef BATTLESHIP_BOAT_H
#define BATTLESHIP_BOAT_H

int can_place_ship(Board * board, int row, int col, int size, int direction);

void place_ship(Board * board, int row, int col, int size, int direction);

int place_ships_randomly(Board * board);

#endif //BATTLESHIP_BOAT_H