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

    int choice;
    int row, col, size, direction;

    printf("Souhaitez-vous placer vos bateaux manuellement ou automatiquement?\n");
    printf("1. Automatiquement.\n");
    printf("2. Manuellement.\n");
    printf("\n");

    // scanf("%d", &choice);
    choice=1; // pour faciliter

    // scanf("%d %d %d %d", &row, &col, &size, &direction);

    Player * p1 = malloc(sizeof(Player));
    p1->id=0;
    p1->board.size = BOARD_SIZE;
    
    Player * p2 = malloc(sizeof(Player));
    p2->id=1;
    p2->board.size = BOARD_SIZE;

    allocate_board(&(p1->board));
    allocate_board(&(p2->board));

    switch (choice)
    {
    case 1:
        place_ships_randomly(&(p1->board));
        place_ships_randomly(&(p2->board));
        launch_game();
        break;
    case 2:
        // TODO: cas d'ajout de navires manuellement
    default:
        printf("Saisie incorrecte.");
    }

    print_board(&(p1->board));

    free_board(&(p1->board));
    free(p1);


    exit(EXIT_SUCCESS);
}