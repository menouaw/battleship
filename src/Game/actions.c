//
// Created by menou on 26/09/2025.
//
#include <stdio.h>

#include "../../include/Game/board.h"

Position get_player_input(void)
{
    Position pos;
    int row;
    int col;
    int bool = 0;
    int size = BOARD_SIZE;

    do
    {
        printf("Où souhaitez-vous tirer? Format: X,Y.\n");
        scanf("%d,%d", &row, &col);

        if ((row<0||row>size-1)||
            (col<0||col>size-1))
        {
            continue;
        } else
        {
            bool = 1;
        }

    } while (bool != 0);

    pos.row = row;
    pos.col = col;

    return pos;
}

void attack(Board * opponentBoard, Position position)
{
}

int launch_game(Player * p1, Player * p2)
{
    /*
     * 1. afficher
     * 2. obtenir l'attaque
     * 3. traiter l'attaque
     * 4. vérifier victoire
     * 5. changement de joueur
     */

    int winner = -1;
    int turn = 0;
    Position pos;

    while (winner==-1)
    {
        if (turn%2) // tour du joueur 1
        {
            printf("Tour du joueur 1\n");
            pos = get_player_input();


        } else // tour du joueur 2
        {

        }
        ++turn;
    }
}


#include "../../include/Game/actions.h"
