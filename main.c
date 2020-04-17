#include "input_output.h"
#include "turn.h"
#include <stdbool.h>
#include <stdio.h>

bool movePoss(square board[BOARD_SIZE][BOARD_SIZE], player players[2], int curPlayer);

int main(void)
{
    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];
    bool gameEnd = false;
    int winning_Player, losing_Player;

    initialize_players(players);//Call to initialize_players function which is contained within game_init.h

    initialize_board(board);//Call to initialize_board function which is contained within game_init.h

    print_board(board);//Call to print_board function which will print the initialised board

    while (gameEnd != true)
    {
        if (movePoss(board, players, 0) == true)
        {
            playerTurn(players, board, 0);
            print_board(board);
        }
        else{
            winning_Player = 0;
            losing_Player = 1;
            gameEnd = true;
        }

        if (movePoss(board, players, 1) == true)
        {
            playerTurn(players, board, 1);
            print_board(board);
        }
        else{
            winning_Player = 1;
            losing_Player = 0;
            gameEnd = true;
        }

    }

    printf("\nThe game has ended.\n"
           "%s has won the game having dominated %d pieces.\n"
           "Better luck next time %s.",
           players[winning_Player].pname, players[winning_Player].dom_Pieces, players[losing_Player].pname);
}

//Function will check if a player has any potential moves left available to him
//Will return true if a move is available else will return false
bool movePoss(square board[BOARD_SIZE][BOARD_SIZE], player players[2], int curPlayer)
{
    int t, k;
    //Loop will check if player has any stacks left on the board
    for(t=0;t<BOARD_SIZE;t++)
    {
        for(k=0;k<BOARD_SIZE;k++)
        {
            if(board[t][k].stack != NULL)
            {
                if(board[t][k].stack->p_color == players[curPlayer].player_Colour)
                {
                    return true;
                }
            }
        }
    }

    //Checking if the player has any reserve pieces remaining
    if(players[curPlayer].res_Pieces != 0)
    {
        return true;
    }
    else{
        return false;
    }
}