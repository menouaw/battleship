//
// Created by menou on 26/09/2025.
//

#include "../../include/Game/interface.h"

#include <stdio.h>

#include "../../include/Game/board.h"

Position get_player_input(void)
{
    Position pos;
    int row;
    int col;
    int bool = 0;
    int size = BOARD_SIZE;
    int result;
    char buffer[99];

    do
    {
        printf("O%c souhaitez-vous tirer? Format: X,Y.\n", 151);
        result = scanf("%d,%d", &row, &col);

        while (getchar()!='\n');

        if (result != 2)
        {
            printf("Format incorrect. Exemple de format correct: 2, 3.\n");
        } else if ((row<0||row>size-1)||
            (col<0||col>size-1))
        {
            printf("Coordonn%ces hors limites. Valeur minimale: 0, valeur maximale: %d.\n", 130, size);
        } else
        {
            printf("\n");
            bool = 1;
        }

    } while (bool == 0);

    pos.row = row;
    pos.col = col;

    return pos;
}

void print_player_interface(Player * player)
{
    printf("=== Au tour du joueur %d ===\n", (player->id)+1);
    printf("Votre plateau: \n");
    print_board(&player->board);
    printf("Le plateau de votre adversaire: \n");
    print_board(&player->own_opponent_board);
}

void clear_screen()
{
    // system("clear");
    system("cls");
}

void wait_for_next_player()
{
    printf("Appuyez sur la touche 'Entr%ce pour passer au joueur suivant.\n", 130);
    getchar();
    clear_screen();
}
