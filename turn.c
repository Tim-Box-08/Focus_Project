//Timothy O'Shea
//19333841
//Contains all the functionality required for a player to take a turn in the game
#include "game_init.h"
#include "turn.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Function prototypes
bool moveCheck(int moveType, int curRow, int curCol);
void merge(square board[BOARD_SIZE][BOARD_SIZE],int k, int t, int curRow, int curCol, int moveNum);
void removeExcess(square board[BOARD_SIZE][BOARD_SIZE], int curRow, int curCol, player players[2], int curPlayer);
bool insert(square board[BOARD_SIZE][BOARD_SIZE], player players[2], int k, int t, int curPlayer);

void playerTurn(player players[2], square board[BOARD_SIZE][BOARD_SIZE], int curPlayer)
{
    int k = 0, t = 0, h = 0, moveNum, moveType, curRow, curCol;

    printf("It is currently %s's turn\n", players[curPlayer].pname);

    //Allowing the player to select a piece
    //Statement will loop until a valid piece is selected
    while (h == 0) {
        if(players[curPlayer].player_Colour == RED)
        {
            printf("Select a RED piece\n");
        } else{
            printf("Select a GREEN piece\n");
        }

        //Player selects a position on the board
        printf("Please select a row:");
        scanf("%d", &k);
        printf("Please select a column:");
        scanf("%d", &t);

        if (board[k][t].type == VALID)
        {
            if (board[k][t].stack != NULL)
            {
                if (board[k][t].stack->p_color == players[curPlayer].player_Colour) {
                    h = 1;
                } else{
                    printf("\nThe square you selected belongs to the other player\n\nPlease select another square\n");
                }
            }
            //Statement will trigger if player selects an empty square on the board
            else
            {
                if(players[curPlayer].res_Pieces > 0)
                {
                    if (insert(board, players, k, t, curPlayer) == true)
                    {
                        return;
                    } else {
                        printf("\nYou decided not to place a piece on the board\n\nPlease select another square on the board\n");
                    }
                } else{
                    printf("\nYou do not have pieces in reserve\n\nPlease select another square on the board\n");
                }
            }
        }
    }

    //curRow and curCol will act as a cursor used to track position on the board
    curRow = k;
    curCol = t;

    //Number of squares a piece will move is decide by size of stack
    for (moveNum = 0; moveNum < board[k][t].num_pieces; moveNum++) {
        printf("\nYou are currently at position [%d][%d]\n", curRow, curCol);

        printf("Please select a direction in which to move the piece\nEnter 1 for left, 2 for right, 3 for up and 4 for down or 5 to end movement at current position:");
        scanf("%d", &moveType);

        //Cursor will move around the board based on the direction a player wishes to move
        if (moveCheck(moveType, curRow, curCol) == true)
        {
            switch (moveType)
            {
                case 1:
                    curRow = curRow;
                    curCol -= 1;
                    break;
                case 2:
                    curRow = curRow;
                    curCol += 1;
                    break;
                case 3:
                    curRow -= 1;
                    curCol = curCol;
                    break;
                case 4:
                    curRow += 1;
                    curCol = curCol;
                    break;
                case 5:
                    moveNum = 5;
                    break;
                default:
                    break;
            }
            continue;
        }
        //Statement will trigger if selected move is not a valid one based on the cursors current position
        else{
            printf("\nSelected move is invalid\n");
            moveNum -= 1;
            continue;
        }
    }

    merge(board, k, t, curRow, curCol, moveNum);//Call to merge function which will combine the two identified stacks
    board[k][t].stack = NULL;//Resets the pointer in the now vacant board square to NULL
    board[k][t].num_pieces = 0;//Resets the counter for the number of pieces on the now vacant board square to 0

    //Call to function will trigger if the stack contains more that 5 pieces
    if(board[curRow][curCol].num_pieces>5)
    {
        removeExcess(board, curRow, curCol, players, curPlayer);
    }
}

//Function to merge two stacks together
void merge(square board[BOARD_SIZE][BOARD_SIZE], int k, int t, int curRow, int curCol, int moveNum)
{
    int curPosition = 0;
    piece * curr;//Pointer to a struct of type piece
    piece * next;
    curr = board[k][t].stack;//Curr is initialised with the address of the top of the stack to be added
    //While loop will continue execution until the bottom of the stack is reached
    while(curPosition < moveNum)
    {
        curr = curr->next;
        curPosition++;
    }
    
    if(curr->next == NULL) {
        curr->next = board[curRow][curCol].stack;//The pointer at the bottom of the stack is updated to point to the top of the other stack
        board[curRow][curCol].stack = board[k][t].stack;//Makes it so that the board pointer now points to the new top of the stack
        board[curRow][curCol].num_pieces += board[k][t].num_pieces;//Updates the counter for the number of pieces in the stack
        board[k][t].stack = NULL;//Resets the pointer in the now vacant board square to NULL
        board[k][t].num_pieces = 0;//Resets the counter for the number of pieces on the now vacant board square to 0
    } else{
        next = curr->next;
        curr->next = board[curRow][curCol].stack;
        board[curRow][curCol].stack = board[k][t].stack;
        board[curRow][curCol].num_pieces += moveNum;
        board[k][t].stack = next;
        board[k][t].num_pieces -= moveNum;
    }
}

//Function to check the validity of a player's move
bool moveCheck(int moveType, int curRow, int curCol)
{
   bool validMove = true;//Move is initial assumed to be valid

   //Switch statement will check the proposed move against a list of invalid moves based on the players current position on the board
   //If a proposed move is invalid the statement will alter the validMove bool to reflect that fact
   switch(curRow)
   {
       case 0:
           switch (curCol) {
               case 2:
                   if (moveType == 3 || moveType == 1) {
                       validMove = false;
                   }
                   break;
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
               default:
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
               default:
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
               default:
                   break;
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
               default:
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
               default:
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
               default:
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
               default:
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
               default:
                   break;
           }
           break;
       default:
           break;
   }

    return validMove;//Returns a boolean which reflects the validity of the move
}

//Function will remove pieces from a stack until it's size is set to 5
void removeExcess(square board[BOARD_SIZE][BOARD_SIZE], int curRow, int curCol, player players[2], int curPlayer)
{
    piece * previous = NULL;//Pointer to piece above that that pointed to by curr
    piece * curr = NULL;//Pointer to a struct of type piece

    while(board[curRow][curCol].num_pieces > 5)
    {
        curr = board[curRow][curCol].stack;//Curr is initialised with the address of the top of the stack

        //While loop will continue execution until the bottom of the stack is reached
        while (curr->next != NULL)
        {
            previous = curr;
            curr = curr->next;
        }
        //Incrementing the number of pieces a player has in reserve
        if(curr->p_color == players[curPlayer].player_Colour)
        {
            players[curPlayer].res_Pieces += 1;
        }
        //Incrementing the number of pieces a player has dominated
        else{
            players[curPlayer].dom_Pieces += 1;
        }
        //Setting the element above that pointed to by curr as the new bottom of the stack
        previous->next = NULL;
        //Freeing up the memory pointed to by curr
        free(curr);
        //Decreasing the count of the number of pieces in the stack
        board[curRow][curCol].num_pieces -= 1;
    }
}

//Function to place a piece on an empty square
bool insert(square board[BOARD_SIZE][BOARD_SIZE], player players[2], int k, int t, int curPlayer)
{
    bool insertionMade = false;
    int choice;
    //Gives player the option to select a non empty position
    printf("You have selected a empty square.\n"
           "You currently have %d pieces in reserve.\n"
           "Would you like to insert a piece onto this position?\n"
           "Type 1 for yes or 2 for no: ", players[curPlayer].res_Pieces);
    scanf("%d", &choice);

    if(choice == 1)
    {
      switch(curPlayer)
      {
          case 0:
              set_red(&board[k][t]);
              players[curPlayer].res_Pieces -= 1;
              insertionMade = true;
              break;
          case 1:
              set_green(&board[k][t]);
              players[curPlayer].res_Pieces -= 1;
              insertionMade = true;
              break;
          default:
              break;
      }
      //Returning confirmation that a piece was inserted
      return insertionMade;
    }
    else{
        //Return confirmation that an insertion was not made
        return insertionMade;
    }
}
