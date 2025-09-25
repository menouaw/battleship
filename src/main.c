#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/Game/map.h"
#include "../include/Game/ship.h"
#include "../include/DataStructures/bases.h"

#define BOARD_SIZE 5;

int main(int argc, char * argv[])
{
    srand((unsigned int)time(NULL));
    int row, col, size, direction;

    // scanf("%d %d %d %d", &row, &col, &size, &direction);

    Board * board_player1 = malloc(sizeof(Board));
    board_player1->size=BOARD_SIZE;

    allocate_board(board_player1);

    // if (can_place_ship(board_player1, row, col, size, direction))
    // {
    //     place_ship(board_player1, row, col, size, direction);
    // }

    place_ships_randomly(board_player1);

    print_board(board_player1);

    free_board(board_player1);

    exit(EXIT_SUCCESS);
}