//
// Created by ttoto on 03/04/2020.
//
#include "game_init.c"
#include "turn.h"
#include <stdio.h>

void playerTurn(player currentPlayer, square board[BOARD_SIZE][BOARD_SIZE])
{
    int k=0, t=0, h=0, moveNum, moveType, curRow, curCol;

    //Allowing the player to select a piece
    while(h==0)
    {
        printf("Please select a row:");
        scanf("%d", &k);
        printf("Please select a column:");
        scanf("%d", &t);

        if (board[k][t].type == VALID && board[k][t].stack->p_color == currentPlayer.player_Colour) {
            h = 1;
        }
        else{
            printf("Please select a valid square.\n Valid squares have the same colour as the current player and are valid squares on the board");
        }
    }

    curRow = k;
    curCol = t;

    for(moveNum=0;moveNum<board[k][t].num_pieces;moveNum++)
    {
        printf("Please select a direction in which to move the piece\nEnter 1 for left, 2 for right, 3 for up and 4 for down:");
        scanf("%d", &moveType);

        switch (moveType)
        {
            case 1:
                curRow = curRow;
                curCol -= curCol;
                break;
            case 2:
                curRow = curRow;
                curCol += curCol;
                break;
            case 3:
                curRow -= curRow;
                curCol = curCol;
                break;
            case 4:
                curRow += curRow;
                curCol = curCol;
        }
    }



}

