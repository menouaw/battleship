//
// Created by menou on 25/09/2025.
//
#include <stdlib.h>
#include "../DataStructures/bases.h"

#ifndef BATTLESHIP_BOAT_H
#define BATTLESHIP_BOAT_H

#define NB_PORTE_AVIONS 1
#define NB_CROISEUR 1
#define NB_DESTROYER 2
#define NB_TORPILLEUR 1

#define SIZE_PORTE_AVIONS 5
#define SIZE_CROISEUR 4
#define SIZE_DESTROYER 3
#define SIZE_TORPILLEUR 2


int can_place_ship(Board * board, int row, int col, int size, int direction);

void place_ship(Board * board, int row, int col, int size, int direction);

int place_ships_manually(Board * board);

int place_ships_randomly(Board * board);

#endif //BATTLESHIP_BOAT_H