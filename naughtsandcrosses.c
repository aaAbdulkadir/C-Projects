#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

/* ------------------ GLOBAL VARIABLES ------------------ */

// empty board
char theBoard[10] = {'a', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// assign turn
char turn[2] = {'X', 'O'};
int player = 1;

/* ------------------ DECLARE FUNCTIONS ------------------ */
void printBoard(void);
void handleTurn(void);
void switchPlayer (void);
void findWinner();

/* ------------------ MAIN ------------------ */
int main(void)
{
    printf("\n===================================================================================\n");
    printf("*************************************TICTACTOE*************************************\n");
    printf("===================================================================================\n");

    // welcome message
    printf("\nHello welcome to tictactoe, get ready for an exhilterating game!");

    // rules
    printf("\n\nThe rules are simple. You must pick a position between 1 and 9, corresponding to \nthe board which will be displayed below: \n");

    // initially print the board to let user know placements
    printf("\n   |   |   \n");
    printf(" 1 | 2 | 3 \n");
    printf("   |   |   \n");
    printf("---|---|---\n");
    printf("   |   |   \n");
    printf(" 4 | 5 | 6 \n");    
    printf("   |   |   \n");
    printf("---|---|---\n");
    printf("   |   |   \n");
    printf(" 7 | 8 | 9 \n");    
    printf("   |   |   \n\n");

    printf("If you get three in a row, you win. Good luck!\n");

    printf("\n===================================================================================\n");
    printf("*************************************LETS PLAY*************************************\n");
    printf("===================================================================================\n\n");

    // algorithm for game
    for (int i = 0; i < 9; i++)
    {
        handleTurn(); 
        printBoard();
        findWinner();
        switchPlayer();
    }
}

/* ------------------ FUNCTIONS ------------------ */

void handleTurn(void)
{
    // ask for where they want to place . if condition to distinguish which player
    if (player == 1)
    {
        printf("Turn for player %d (%c). Where do you want to position yourself: ", player, turn[0]);
    }
    else
    {
        printf("Turn for player %d (%c). Where do you want to position yourself: ", player, turn[1]);
    }
    
    // initialise move
    int move;
    
    // boolean
    bool isTrue = true;

    while (isTrue == true)
    {
        scanf("%d", &move);

        if (move >= 1 && move <= 9)
        {
            if ((theBoard[move] == turn[0]) || (theBoard[move] == turn[1]))
            {
                printf("That position has already been taken, pick again: ");
                continue;
            }
            else
            {
                // works with switching player
                if (player == 1)
                {
                    theBoard[move] = turn[0];
                }
                else
                {
                    theBoard[move] = turn[1];
                }
                isTrue = false;
            }
        }
        else
        {
            printf("Enter a valid input: ");
        }

        // stop non-digit inputs TODO
    }
}

void printBoard(void)
{
    printf("Player 1 (X)  -  Player 2 (O)\n\n");

    // the board printing format
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", theBoard[1], theBoard[2], theBoard[3]);
    printf("   |   |   \n");
    printf("---|---|---\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", theBoard[4], theBoard[5], theBoard[6]);      
    printf("   |   |   \n");
    printf("---|---|---\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", theBoard[7], theBoard[8], theBoard[9]);
    printf("   |   |   \n\n");
    printf("------------------------------------------------\n\n");
}

void switchPlayer(void)
{
    if (player == 1)
    {
        player = 2;
    }
    else
    {
        player = 1;
    }
}

void findWinner()
{
    // horizontal
    if ((theBoard[1] == theBoard[2] && theBoard[2] == theBoard[3]) || (theBoard[4] == theBoard[5] && theBoard[5] == theBoard[6]) || (theBoard[7] == theBoard[8] && theBoard[8] == theBoard[9]))
    {
        if (player == 1)
        {
            printf("%c has won!\n", turn[0]);
            exit(0);
        }
        else
        {
            printf("%c has won!\n", turn[1]);
            exit(0);
        }
    }
    // vertical
    else if ((theBoard[1] == theBoard[4] && theBoard[4] == theBoard[7]) || (theBoard[2] == theBoard[5] && theBoard[5] == theBoard[8]) || (theBoard[3] == theBoard[6] && theBoard[6] == theBoard[9]))
    {
        if (player == 1)
        {
            printf("%c has won!\n", turn[0]);
            exit(0);
        }
        else
        {
            printf("%c has won!\n", turn[1]);
            exit(0);
        }
    }
    // diagonal
    else if ((theBoard[1] == theBoard[5] && theBoard[5] == theBoard[9]) || (theBoard[3] == theBoard[5] && theBoard[5] == theBoard[7]))
    {
        if (player == 1)
        {
            printf("%c has won!\n", turn[0]);
            exit(0);
        }
        else
        {
            printf("%c has won!\n", turn[1]);
            exit(0);
        }
    }
}