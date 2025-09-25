//
// Created by menou on 25/09/2025.
//

#include "../../include/Game/map.h"

#include <stdio.h>
#include <stdlib.h>

void allocate_board(Board * board)
{
    board->board = malloc(sizeof(char*) * board->size);

    for (int i = 0; i < board->size; ++i)
    {
        board->board[i] = malloc(sizeof(char) * board->size);

        for (int j = 0; j < board->size+1; ++j)
        {
            board->board[i][j] = '.';
        }
    }
}

void print_board(const Board * board)
{
    int i = 0;
    int j = 0;

    // en-tête
    for (i=0; i < board->size+1; ++i)
    {
        if (i==0)
        {
            printf("%3c", 'X');
        }

        printf("%3c ", 65+i);

        if (i==board->size)
        {
            printf("\n");
        }
    }

    for (i=0; i < board->size; ++i)
    {
        printf("%2d ", i+1);

        for (j=0; j < board->size+1; ++j)
        {
            printf("%3c ", board->board[i][j]);
        }
        printf("\n");
    }
}

void free_board(Board * board)
{
    free(board);
}