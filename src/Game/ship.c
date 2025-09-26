//
// Created by menou on 25/09/2025.
//

#include "../../include/Game/ship.h"

#include <stdio.h>

#include "../../include/Game/board.h"

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

    if (can_place_ship(board, row, col, size, direction))
    {
        if (direction == 0)
        {
            for (i = 0; i < size; ++i)
            {
                board->board[row][col+i] = (char)(size + 48);
            }
        }
        else if (direction == 1)
        {
            for (i = 0; i < size; ++i)
            {
                board->board[row+i][col] = (char)(size + 48);
            }
        }
        else if (direction == 2)
        {
            for (i = 0; i < size; ++i)
            {
                board->board[row][col-i] = (char)(size + 48);
            }
        }
        else if (direction == 3)
        {
            for (i = 0; i < size; ++i)
            {
                board->board[row-i][col] = (char)(size + 48);
            }
        }
    }
    else
    {
        printf("Dimensions incorrectes.\n");
    }
}


int place_ships_manually(Board * board)
{
    int i;
    int row, col, direction;
    int bool;

    printf("Guide de direction:\n"
           "0: vers la droite,\n"
           "1: vers le bas,\n"
           "2: vers la gauche,\n"
           "3: vers le haut.\n");

    for (i = 0; i < NB_PORTE_AVIONS; ++i)
    {
        do
        {
            bool = 0;
            printf("Saisissez les coordonn%ces et la direction de votre porte-avions n%c%d sur %d (longueur: %d)\n", 130, 167, i+1, NB_PORTE_AVIONS, SIZE_PORTE_AVIONS);
            printf("Format: <ligne>,<colonne>,<direction>. Exemple: 2,1,0\n");
            scanf("%d,%d,%d,%d", &row, &col, &direction);
            bool = can_place_ship(board, row, col, SIZE_PORTE_AVIONS, direction);

            if (bool)
            {
                place_ship(board, row, col, SIZE_PORTE_AVIONS, direction);
                print_board(board);
            }
        } while (bool==0);
    }

    for (i = 0; i < NB_CROISEUR; ++i)
    {
        do
        {
            bool = 0;
            printf("Saisissez les coordonn%ces et la direction de votre croiseur n%c%d sur %d (longueur: %d)\n", 130, 167, i+1, NB_CROISEUR, SIZE_CROISEUR);
            scanf("%d,%d,%d,%d", &row, &col, &direction);
            bool = can_place_ship(board, row, col, SIZE_CROISEUR, direction);

            if (bool)
            {
                place_ship(board, row, col, SIZE_CROISEUR, direction);
                print_board(board);
            }
        } while (bool==0);
    }

    for (i = 0; i < NB_DESTROYER; ++i)
    {
        do
        {
            bool = 0;
            printf("Saisissez les coordonn%ces et la direction de votre destroyer n%c%d sur %d (longueur: %d)\n", 130, 167, i+1, NB_DESTROYER, SIZE_DESTROYER);
            scanf("%d,%d,%d,%d", &row, &col, &direction);
            bool = can_place_ship(board, row, col, SIZE_DESTROYER, direction);

            if (bool)
            {
                place_ship(board, row, col, SIZE_DESTROYER, direction);
                print_board(board);
            }
        } while (bool==0);
    }

    for (i = 0; i < NB_TORPILLEUR; ++i)
    {
        do
        {
            bool = 0;
            printf("Saisissez les coordonn%ces et la direction de votre torpilleur n%c%d sur %d (longueur: %d)\n", 130, 167, i+1, NB_TORPILLEUR, SIZE_TORPILLEUR);
            scanf("%d,%d,%d,%d", &row, &col, &direction);
            bool = can_place_ship(board, row, col, SIZE_TORPILLEUR, direction);

            if (bool)
            {
                place_ship(board, row, col, SIZE_TORPILLEUR, direction);
                print_board(board);
            }
        } while (bool==0);
    }

    return 1;
}

int place_ships_randomly(Board * board)
{
    int i;
    int attempts = 0;
    int row, col, direction;

    for (i=0; i < NB_PORTE_AVIONS && attempts < 1000;)
    {
        row = rand() % board->size;
        col = rand() % board->size;
        direction = rand() % 4;
        ++attempts;

        if (can_place_ship(board, row, col, SIZE_PORTE_AVIONS, direction))
        {
            place_ship(board, row, col, SIZE_PORTE_AVIONS, direction);
            ++i;
        }
    }

    for (i=0; i < NB_CROISEUR && attempts < 1000;)
    {
        row = rand() % board->size;
        col = rand() % board->size;
        direction = rand() % 4;
        ++attempts;

        if (can_place_ship(board, row, col, SIZE_CROISEUR, direction))
        {
            place_ship(board, row, col, SIZE_CROISEUR, direction);
            ++i;
        }
    }

    for (i=0; i < NB_DESTROYER && attempts < 1000;)
    {
        row = rand() % board->size;
        col = rand() % board->size;
        direction = rand() % 4;
        ++attempts;

        if (can_place_ship(board, row, col, SIZE_DESTROYER, direction))
        {
            place_ship(board, row, col, SIZE_DESTROYER, direction);
            ++i;
        }
    }

    for (i=0; i < NB_TORPILLEUR && attempts < 1000;)
    {
        row = rand() % board->size;
        col = rand() % board->size;
        direction = rand() % 4;
        ++attempts;

        if (can_place_ship(board, row, col, SIZE_TORPILLEUR, direction))
        {
            place_ship(board, row, col, SIZE_TORPILLEUR, direction);
            ++i;
        }
    }

    return 1;
}
