#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/Game/board.h"
#include "../include/Game/ship.h"
#include "../include/DataStructures/bases.h"

#define BOARD_SIZE 5;

int main(int argc, char * argv[])
{
    srand((unsigned int)time(NULL));

    int lives = (NB_PORTE_AVIONS*SIZE_PORTE_AVIONS+
        NB_CROISEUR*SIZE_CROISEUR+
        NB_DESTROYER*SIZE_DESTROYER+
        NB_TORPILLEUR*SIZE_TORPILLEUR);
    int choice;
    int row, col, size, direction;

    printf("Souhaitez-vous placer vos bateaux manuellement ou automatiquement?\n");
    printf("1. Automatiquement.\n");
    printf("2. Manuellement.\n");
    printf("\n");

    // scanf("%d", &choice);
    choice=1; // pour faciliter le dev

    // scanf("%d %d %d %d", &row, &col, &size, &direction);

    Player * p1 = malloc(sizeof(Player));
    p1->id=0;
    p1->lefts=lives;
    p1->board.size = BOARD_SIZE;

    Player * p2 = malloc(sizeof(Player));
    p2->id=1;
    p2->lefts=lives;
    p2->board.size = BOARD_SIZE;

    allocate_board(&(p1->board));
    allocate_board(&(p1->own_opponent_board));
    allocate_board(&(p2->board));
    allocate_board(&(p2->own_opponent_board));

    switch (choice)
    {
    case 1:
        place_ships_randomly(&(p1->board));
        place_ships_randomly(&(p2->board));
        // TODO: launch_game();
        break;
    case 2:
        // TODO: cas d'ajout de navires manuellement
    default:
        printf("Saisie incorrecte.");
    }

    print_board(&(p1->board));

    free_board(&(p1->board));
    free_board(&(p1->own_opponent_board));
    free(p1);

    free_board(&(p2->board));
    free_board(&(p2->own_opponent_board));
    free(p2);

    exit(EXIT_SUCCESS);
}