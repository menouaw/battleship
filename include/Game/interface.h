//
// Created by menou on 26/09/2025.
//
#include <stdlib.h>

#include "../DataStructures/bases.h"

#ifndef BATTLESHIP_INTERFACE_H
#define BATTLESHIP_INTERFACE_H

Position get_player_input(void);

void print_player_interface(Player *player);

void clear_screen();

void wait_for_next_player();

#endif //BATTLESHIP_INTERFACE_H