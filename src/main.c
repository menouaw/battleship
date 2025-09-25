#include <stdio.h>
#include <stdlib.h>

#include "../include/Game/map.h"
#include "../include/DataStructures/bases.h"

int main(int argc, char * argv[])
{
    Board * b = malloc(sizeof(Board));
    b->size=5;

    allocate_board(b);
    print_board(b);

    free_board(b);

    exit(EXIT_SUCCESS);
}