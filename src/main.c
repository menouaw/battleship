#include <stdio.h>
#include <stdlib.h>

#include "../include/Game/map.h"
#include "../include/Game/ship.h"
#include "../include/DataStructures/bases.h"

const int SIZE = 5;

int main(int argc, char * argv[])
{
    Board * board_player1 = malloc(sizeof(Board));
    board_player1->size=SIZE;

    allocate_board(board_player1);

    fprintf(stderr, "%d\n", can_place_ship(board_player1, 0, 0, 1, 2));
    place_ship(board_player1, 2, 2, 3, 2);

    print_board(board_player1);


    free_board(board_player1);

    exit(EXIT_SUCCESS);
}