//
// Created by menou on 26/09/2025.
//
#include "../DataStructures/bases.h"

#ifndef BATTLESHIP_ACTIONS_H
#define BATTLESHIP_ACTIONS_H

Position get_player_input(void);

int attack(Position position, Player * opponent, Board * own_opponent_board);

int launch_game(Player * p1, Player * p2);

#endif //BATTLESHIP_ACTIONS_H