//
// Created by menou on 26/09/2025.
//

#include "../../include/Game/checks.h"

#include <stdio.h>

int hit_or_miss(Position position, Board * opponent_board, Board * own_opponent_board)
{
    int res;
    if (opponent_board->board[position.row][position.col]=='.')
    {
        own_opponent_board->board[position.row][position.col]='O';
        printf("Position: %d, %d: à l'eau!\n", position.row, position.row);
        res = -1;
    } else if (opponent_board->board[position.row][position.col]!='.') // soit un bateau
    {
        own_opponent_board->board[position.row][position.col]='X';
        opponent_board->board[position.row][position.col]='X';
        printf("Position: %d, %d: touché!\n", position.row, position.row);
        res = 1;
    } else
    {
        res = 0;
    }
    return res;
}

int victory(Board * board)
{
    int bool = 0;
    int size = board->size;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (board[i][j]
        }
    }
}
