//
// Created by menou on 26/09/2025.
//
#include <stdio.h>

#include "../../include/Game/board.h"

Position get_player_input(Player * player)
{
    Position pos;
    int row;
    int col;
    int bool = 0;
    int size = player->board.size;

    do
    {
        printf("Où souhaitez-vous tirer? Format: X,Y.\n");
        scanf("%d,%d", &row, &col);

        if ((row<0||row>size-1)||
            (col<0||col>size-1))
        {
            continue;
        } else
        {
            bool = 1;
        }

    } while (bool != 0);

    pos.row = row;
    pos.col = col;

    return pos;
}

void attack(Board * opponentBoard, Position position) {}


#include "../../include/Game/actions.h"
