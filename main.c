#include "input_output.h"
#include "turn.h"


int main()
{
    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);//Call to initialize_players function which is contained within game_init.h

    initialize_board(board);//Call to initialize_board function which is contained within game_init.h

    print_board(board);//Call to print_board function which will print the initialised board

    for(int t=0;t<5;t++)
    {
        if(t%2 == 0)
        {
            playerTurn(players[0], board);
        }
        else{
            playerTurn(players[1], board);
        }

        print_board(board);
    }

    return 0;
}
