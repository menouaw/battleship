//
// Created by menou on 26/09/2025.
//
#include <stdio.h>

#include "../../include/Game/actions.h"
#include "../../include/Game/checks.h"
#include "../../include/Game/interface.h"

int attack(Position position, Player * opponent, Board * own_opponent_board)
{
    int res;
    if (opponent->board.board[position.row][position.col]=='.')
    {
        own_opponent_board->board[position.row][position.col]='O';
        printf("Position: %d, %d: %c l'eau!\n", position.row, position.col, 133);
        res = -1;
    } else if (opponent->board.board[position.row][position.col]!='.') // soit un bateau
    {
        own_opponent_board->board[position.row][position.col]='X';
        opponent->board.board[position.row][position.col]='X';
        printf("Position: %d, %d: touch%c!\n", position.row, position.col, 130);
        opponent->lefts-=1;
        res = 1;
    } else
    {
        res = 0;
    }
    return res;
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
    int bool_hit = 0;
    Position pos;

    while (winner==-1)
    {
        if (turn%2==0) // tour du joueur 1
        {
            do
            {
                bool_hit = 0;
                print_player_interface(p1);
                pos = get_player_input();
                bool_hit = attack(pos, p2, &p1->own_opponent_board);
                if (victory(p2)==0)
                {
                    winner=1;
                    break;
                }
            } while (bool_hit>0);

        } else // tour du joueur 2
        {
            do
            {
                bool_hit = 0;
                print_player_interface(p2);
                pos = get_player_input();
                bool_hit = attack(pos, p1, &p2->own_opponent_board);
                if (victory(p1)==0)
                {
                    winner=2;
                    break;
                }
            } while (bool_hit>0);
        }
        ++turn;
    }
    return winner;
}
