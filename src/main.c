#include <stdio.h>
#include <stdlib.h>

#include "../include/Game/map.h"
#include "../include/DataStructures/bases.h"

const int SIZE = 5;

int main(int argc, char * argv[])
{
    Board * b = malloc(sizeof(Board));
    b->size=SIZE;

    allocate_board(b);
    b->board[2][4] = 'a';

    print_board(b);


    free_board(b);

    exit(EXIT_SUCCESS);
}