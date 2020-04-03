//
// Created by ttoto on 03/04/2020.
//
#include "game_init.c"
#include "turn.h"
#include <stdio.h>
#include <stdbool.h>

bool moveCheck(int moveType, int curRow, int curCol)

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
            printf("Please select a valid square.\n Valid squares have the same colour as the current player and are valid positions on the board");
        }
    }

    curRow = k;
    curCol = t;

    for(moveNum=0;moveNum<board[k][t].num_pieces;moveNum++)
    {
        printf("Please select a direction in which to move the piece\nEnter 1 for left, 2 for right, 3 for up and 4 for down:");
        scanf("%d", &moveType);
        if(moveCheck(moveType, curRow, curCol) == true) {
            switch (moveType) {
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
            continue;
        }
        else
        {
            printf("Selected move is invalid\n");
            moveNum -= 1;
            continue;
        }
    }
}

bool moveCheck(int moveType, int curRow, int curCol)
{
   bool validMove = true;

   //Switch statement will check the proposed move against a list of invalid moves based on the players current position on the board
   switch(curRow)
   {
       case 0:
           switch (curCol) {
               case 2:
                   if (moveType == 3 || moveType == 1) {
                       validMove = false;
                   }
               case 3:
                   if (moveType == 3) {
                       validMove = false;
                   }
                   break;
               case 4:
                   if (moveType == 3) {
                       validMove = false;
                   }
                   break;
               case 5:
                   if (moveType == 3 || moveType == 2) {
                       validMove = false;
                   }
                   break;
           }
           break;
       case 1:
           switch (curCol) {
               case 1:
                   if (moveType == 3 || moveType == 1) {
                       validMove = false;
                   }
                   break;
               case 6:
                   if (moveType == 3 || moveType == 2) {
                       validMove = false;
                   }
                   break;
           }
           break;
       case 2:
           switch (curCol) {
               case 0:
                   if (moveType == 3 || moveType == 1) {
                       validMove = false;
                   }
                   break;
               case 7:
                   if (moveType == 3 || moveType == 2) {
                       validMove = false;
                   }
           }
           break;
       case 3:
           switch (curCol) {
               case 0:
                   if (moveType == 1) {
                       validMove = false;
                   }
                   break;
               case 7:
                   if (moveType == 2) {
                       validMove = false;
                   }
                   break;
           }
           break;
       case 4:
           switch (curCol) {
               case 0:
                   if (moveType == 1) {
                       validMove = false;
                   }
                   break;
               case 7:
                   if (moveType == 2) {
                       validMove = false;
                   }
                   break;
           }
           break;
       case 5:
           switch (curCol) {
               case 0:
                   if (moveType == 1 || moveType == 4) {
                       validMove = false;
                   }
                   break;
               case 7:
                   if (moveType == 2 || moveType == 4) {
                       validMove = false;
                   }
                   break;
           }
           break;
       case 6:
           switch (curCol) {

               case 1:
                   if (moveType == 1 || moveType == 4) {
                       validMove = false;
                   }
                   break;
               case 6:
                   if (moveType == 2 || moveType == 4) {
                       validMove = false;
                   }
                   break;
           }
           break;
       case 7:
           switch(curCol)
           {
               case 2:
                   if (moveType == 1 || moveType == 4) {
                       validMove = false;
                   }
               break;
               case 3:
                   if (moveType == 4) {
                       validMove = false;
                   }
               break;
               case 4:
                   if (moveType == 4) {
                       validMove = false;
                   }
               break;
               case 5:
                   if (moveType == 2 || moveType == 4) {
                       validMove = false;
                   }
               break;
           }
           break;
   }

   return validMove;
}