//
// Created by menou on 25/09/2025.
//

#include "../../include/Game/ship.h"

int can_place_ship(Board * board, int row, int col, int size, int direction)
{
    int i;

    if (size<1 ||
        (direction<0||direction>3) ||
        (row>board->size||row<0)||
        (col>board->size||col<0)) return 0;

    //est
    if (direction==0)
    {
        if (col + size > board->size)
        {
            return 0;
        }

        for (i = 0; i < size; ++i)
        {
            if (board->board[row][col+i] != '.')
            {
                return 0;
            }
        }
        return 1;
    }

    //sud
    if (direction==1)
    {
        if (row + size > board->size)
        {
            return 0;
        }

        for (i = 0; i < size; ++i)
        {
            if (board->board[row+i][col] != '.')
            {
                return 0;
            }
        }
        return 1;
    }

    //ouest
    if (direction==2)
    {
        if (col - size + 1 < 0)
        {
            return 0;
        }

        for (i = 0; i < size; ++i)
        {
            if (board->board[row][col-i] != '.')
            {
                return 0;
            }
        }
        return 1;
    }
    //nord
    if (direction==3)
    {
        if (row - size + 1 < 0)
        {
            return 0;
        }

        for (i = 0; i < size; ++i)
        {
            if (board->board[row-i][col] != '.')
            {
                return 0;
            }
        }
        return 1;
    }

    return 0;
}

void place_ship(Board* board, int row, int col, int size, int direction)
{
    int i;

    //est
    if (direction==0)
    {
        for (i = 0; i < size; ++i)
        {
            board->board[row][col+i]=(char)(size + 48);
        }
    }

    //sud
    if (direction==1)
    {
        for (i = 0; i < size; ++i)
        {
            board->board[row+i][col]=(char)(size + 48);
        }
    }

    //ouest
    if (direction==2)
    {
        for (i = 0; i < size; ++i)
        {
            board->board[row][col-i]=(char)(size + 48);
        }
    }

    //nord
    if (direction==3)
    {
        for (i = 0; i < size; ++i)
        {
            board->board[row-i][col]=(char)(size + 48);
        }
    }

}

int place_ships_randomly(Board* board)
{
}
