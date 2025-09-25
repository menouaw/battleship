//
// Created by menou on 26/09/2025.
//
#include "../DataStructures/bases.h"

#ifndef BATTLESHIP_ACTIONS_H
#define BATTLESHIP_ACTIONS_H

Position get_player_input(Player * player, int col, int row);

void attack(Board * opponent_board, Position position);

#endif //BATTLESHIP_ACTIONS_H