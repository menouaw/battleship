//
// Created by menou on 26/09/2025.
//

#include "../../include/Game/checks.h"

#include <stdio.h>

int hit_or_miss(Position position, Player * opponent, Board * own_opponent_board)
{
    int res;
    if (opponent->board.board[position.row][position.col]=='.')
    {
        own_opponent_board->board[position.row][position.col]='O';
        printf("Position: %d, %d: à l'eau!\n", position.row, position.col);
        res = -1;
    } else if (opponent->board.board[position.row][position.col]!='.') // soit un bateau
    {
        own_opponent_board->board[position.row][position.col]='X';
        opponent->board.board[position.row][position.col]='X';
        printf("Position: %d, %d: touché!\n", position.row, position.col);
        opponent->lefts-=1;
        res = 1;
    } else
    {
        res = 0;
    }
    return res;
}

int victory(Player * opponent)
{
    int bool = 0;
    if (opponent->lefts==0)
    {
        bool = 1;
    }
    return bool;
}
