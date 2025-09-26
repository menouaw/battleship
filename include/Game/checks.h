//
// Created by menou on 26/09/2025.
//
#include "../DataStructures/bases.h"

#ifndef BATTLESHIP_CHECKS_H
#define BATTLESHIP_CHECKS_H

int hit_or_miss(Position position, Player * opponent, Board * own_opponent_board);

int victory(Player * opponent);

#endif //BATTLESHIP_CHECKS_H