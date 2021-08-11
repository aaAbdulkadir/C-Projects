#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

/* ------------------ GLOBAL VARIABLES ------------------ */

char board[8][8] = {{' ', 'X', ' ', 'X',' ', 'X', ' ', 'X'},
                    {'X', ' ', 'X', ' ','X', ' ', 'X', ' '},
                    {' ', 'X', ' ', 'X',' ', 'X', ' ', 'X'},
                    {' ', ' ', ' ', ' ',' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ',' ', ' ', ' ', ' '},
                    {'O', ' ', 'O', ' ','O', ' ', 'O', ' '},
                    {' ', 'O', ' ', 'O',' ', 'O', ' ', 'O'},
                    {'O', ' ', 'O', ' ','O', ' ', 'O', ' '}};

// assign turn
char turn[2] = {'X', 'O'};
int player = 1;
bool endGame = true;

// rows and columns on board
int row;
int column; // used to turn letters into numbers for positioning   

/* ------------------ DECLARE FUNCTIONS ------------------ */

void printBoard();
void switchPlayer();
void move();
void checkWinner();

/* ------------------ MAIN ------------------ */

int main(void)
{
    printf("Hello, welcome to checkers!\n");
    sleep(1);
    printf("The first person to take all of the opponents pieces win. Good luck!\n");
    sleep(1);

    printf("\n");
    printBoard();

    while (endGame == true)
    {
        move();
        printf("\n");
        printBoard();
        checkWinner();
        switchPlayer();
    }
}

/* ------------------ FUNCTIONS ------------------ */

void move()
{
    int i, j;

    char position[2];
    bool isTrue = true;
    bool logic = true;
    int diagonal;


    start:
        // player 1 or 2
        if (player == 1)
        {
            printf("\nPlayer (%c)'s turn.\n", turn[0]);
        }
        else
        {
            printf("\nPlayer (%c)'s turn.\n", turn[1]);
        }

        // user input for rows and columns
        printf("Pick the spot of the piece you want to move (e.g. 1A, 2B, 3C...): ");
        scanf("%s", position); // capitalise the letter so it doesnt cause problems

    // translate position to the board
    char boardPosition[2] = {position[0], position[1]};

    // set number string to number integer
    if (position[0] == '1')
    {
        row = 0;
    }
    else if (position[0] == '2')
    {
        row = 1;
    }
    else if (position[0] == '3')
    {
        row = 2;
    }
    else if (position[0] == '4')
    {
        row = 3;
    }
    else if (position[0] == '5')
    {
        row = 4;
    }
    else if (position[0] == '6')
    {
        row = 5;
    }
    else if (position[0] == '7')
    {
        row = 6;
    }
    else if (position[0] == '8')
    {
        row = 7;
    }

    // set letters to numbers
    if (position[1] == 'A')
    {
        column = 0;
    }
    else if (position[1] == 'B')
    {
        column = 1;
    }
    else if (position[1] == 'C')
    {
        column = 2;
    }
    else if (position[1] == 'D')
    {
        column = 3;
    }
    else if (position[1] == 'E')
    {
        column = 4;
    }
    else if (position[1] == 'F')
    {
        column = 5;
    }
    else if (position[1] == 'G')
    {
        column = 6;
    }
    else if (position[1] == 'H')
    {
        column = 7;
    }

    // if its player X's turn and O is picked or vice versa, make sure to print and goto start
    if (player == 1)
    {
        if (board[row][column] == 'O' || board[row][column] == 'o')
        {
            printf("You are %c! You cannot move the other player's piece.\n", turn[0]);
            goto start;
        }
    }
    else
    {
        if (board[row][column] == 'X' || board[row][column] == 'x')
        {
            printf("You are %c! You cannot move the other player's piece.\n", turn[1]);
            goto start;
        }
    }
    
    // make the alternate spots on the board unplayable
    for (i = 0; i < 8; i += 2)
    {
        for (j = 0; j < 8; j+=2)
        {
            if (board[row][column] == ' ')
            {
                printf("\nThat position is out of bounds!\n");
                goto start;
            }
            else
            {
                break;
            }
            break;
        }
        break;
    }

    for (i = 1; i < 8; i += 2)
    {
        for (j = 1; j < 8; j += 2)
        {
            if (board[row][column] == ' ')
            {
                printf("\nThat position is out of bounds!\n");
                goto start;
            }
            else
            {
                break;
            }
            break;
        }
        break;
    }

    // asking for positioning
    bool diag = true;

    while (diag == true)
    {
        // If the piece IS a king
        if (board[row][column] == 'x')
        {
            printf("\nWhere do you want to move this piece?\nTOP-LEFT DIAGONAL: 3\tTOP-RIGHT DIAGONAL: 4\nBOTTOM-LEFT DIAGONAL: 1\tBOTTOM-RIGHT DIAGONAL: 2\n");
            printf("Position: ");
            scanf("%d", &diagonal);

            if (diagonal < 1 || diagonal > 4)
            {
                printf("\nInvalid input! Range between 1-4.\n");
            }  
            else
            {
                diag = false;
            }
        }
        // options for non king
        else if (board[row][column] == 'o')
        {
            printf("\nWhere do you want to move this piece?\nTOP-LEFT DIAGONAL: 1\tTOP-RIGHT DIAGONAL: 2\nBOTTOM-LEFT DIAGONAL: 3\tBOTTOM-RIGHT DIAGONAL: 4\n");
            printf("Position: ");
            scanf("%d", &diagonal);

            if (diagonal < 1 || diagonal > 4)
            {
                printf("\nInvalid input! Range between 1-4.\n");
            }  
            else
            {
                diag = false;
            }
        }
        else
        {
            printf("\nWhere do you want to move this piece?\nLEFT DIAGONAL: 1\tRIGHT DIAGONAL: 2\n");
            printf("Position: ");
            scanf("%d", &diagonal);

            if (diagonal < 1 || diagonal > 2)
            {
                printf("\nInvalid input! Either Left (1) or Right (2).\n");
            }  
            else
            {
                diag = false;
            }
        }
    }
        
    // make sure piece is not trapped by other pieces i.e. can have a possible move
    if (player == 1)
    {
        if ((board[row + 1][column - 1] == 'X' || board[row + 1][column - 1] == 'x') && (board[row + 1][column + 1] == 'X' || board[row + 1][column + 1] == 'x'))
        {
            printf("\nThat piece cannot be moved!\n");
            goto start;
        }
    }
    else
    {
        if ((board[row - 1][column - 1] == 'O' || board[row - 1][column - 1] == 'o') && (board[row - 1][column + 1] == 'O'|| board[row - 1][column + 1] == 'o'))
        {   
            printf("\nThat piece cannot be moved!\n");
            goto start;
        }
    }

    // make sure the piece cannot escape the board i.e. contain pieces within borders
    if (player == 1)
    {   
        // column A
        if (column == 0)
        {
            if (diagonal == 1 || diagonal == 3)
            {
                printf("You cannot go there, that is off the board!\n");
                goto start; 
            }
        }
        // column H
        else if (column == 7)
        {
            if (diagonal == 2 || diagonal == 4)
            {
                printf("You cannot go there, that is off the board!\n");
                goto start; 
            }      
        }
    }
    else
    {
        // column A
        if (column == 0)
        {
            if (diagonal == 1 || diagonal == 3)
            {
                printf("You cannot go there, that is off the board!\n");
                goto start;
            }
        }
        // column H
        else if (column == 7)
        {
            if (diagonal == 2 || diagonal == 4)
            {
                printf("You cannot go there, that is off the board!\n");
                goto start;
            }       
        }        
    }
    
    // GAME LOGIC
    while (logic == true)
    {
        if (player == 1)
        {
            // bottom left open spot
            if (diagonal == 1 && board[row + 1][column - 1] == ' ')
            {
                // if the piece becomes a king at that instant
                if (row + 1 == 7)
                {
                    board[row + 1][column - 1] = 'x';
                    board[row][column] = ' ';
                    logic = false;
                }
                // does not become king at that instant
                else
                {
                    // if already king
                    if (board[row][column] == 'x')
                    {
                        board[row + 1][column - 1] = 'x';
                        board[row][column] = ' ';
                        logic = false; 
                    }
                    // not king
                    else
                    {
                        board[row + 1][column - 1] = 'X';
                        board[row][column] = ' ';
                        logic = false; 
                    }
                }
            }
            // king top left open spot
            else if (diagonal == 3 && board[row - 1][column - 1] == ' ')
            {
                board[row - 1][column - 1] = 'x';
                board[row][column] = ' ';
                logic = false;
            }
            // bottom right open spot
            else if (diagonal == 2 && board[row + 1][column + 1] == ' ')
            {
                // if the piece becomes a king at that instant
                if (row + 1 == 7)
                {
                    board[row + 1][column + 1] = 'x';
                    board[row][column] = ' ';
                    logic = false;
                }
                // not king
                else
                {
                    // if already king
                    if (board[row][column] == 'x')
                    {
                        board[row + 1][column + 1] = 'x';
                        board[row][column] = ' ';
                        logic = false; 
                    }
                    // not king
                    else
                    {
                        board[row + 1][column + 1] = 'X';
                        board[row][column] = ' ';
                        logic = false; 
                    }
                }
            }
            // king king top right open
            else if (diagonal == 4 && board[row - 1][column + 1] == ' ')
            {
                board[row - 1][column + 1] = 'x';
                board[row][column] = ' ';
                logic = false;
            }
            // can take opponent piece bottom left
            else if (diagonal == 1 && (board[row + 1][column - 1] == 'O' || board[row + 1][column - 1] == 'o'))
            {   
                // space behind opponents diagonal is free and becomes a king at that instant
                if (board[row + 2][column - 2] == ' ' && row + 2 == 7)
                {
                    board[row + 2][column - 2] = 'x';
                    board[row + 1][column - 1] = ' ';
                    board[row][column] = ' ';
                    logic = false;
                }
                // space behind opponents diagonal is free and does not become a king i.e. already one or not one
                else if (board[row + 2][column - 2] == ' ')
                {
                    // if king
                    if (board[row][column] == 'x')
                    {
                        board[row + 2][column - 2] = 'x';
                        board[row + 1][column - 1] = ' ';
                        board[row][column] = ' ';
                        logic = false;
                    }
                    // if not king
                    else
                    {
                        board[row + 2][column - 2] = 'X';
                        board[row + 1][column - 1] = ' ';
                        board[row][column] = ' ';
                        logic = false;
                    }
                }
            }
            // king can take opponent piece top left
            else if (diagonal == 3 && (board[row - 1][column - 1] == 'O' || board[row - 1][column - 1] == 'o'))
            {
                board[row - 2][column - 2] = 'x';
                board[row - 1][column - 1] = ' ';
                board[row][column] = ' ';
                logic = false;
            }
            // can take opponent piece bottom right
            else if (diagonal == 2 && (board[row + 1][column + 1] == 'O' || board[row + 1][column + 1] == 'o'))
            {
                // space behind opponents diagonal is free and becomes a king
                if (board[row + 2][column + 2] == ' ' && row + 2 == 7)
                {
                    board[row + 2][column + 2] = 'x';
                    board[row + 1][column + 1] = ' ';
                    board[row][column] = ' ';
                    logic = false;
                }
                // space behind opponents diagonal is free and does not become king at that instant
                else if (board[row + 2][column + 2] == ' ')
                {
                    // if king
                    if (board[row][column] == 'x')
                    {
                        board[row + 2][column + 2] = 'x';
                        board[row + 1][column + 1] = ' ';
                        board[row][column] = ' ';
                        logic = false;
                    }
                    // if not king
                    else
                    {
                        board[row + 2][column + 2] = 'X';
                        board[row + 1][column + 1] = ' ';
                        board[row][column] = ' ';
                        logic = false;
                    }
                }
            }
            // king can take opponent piece top right
            else if (diagonal == 4 && (board[row - 1][column + 1] == 'O' || board[row - 1][column + 1] == 'o'))
            {
                board[row - 2][column + 2] = 'x';
                board[row - 1][column + 1] = ' ';
                board[row][column] = ' ';
                logic = false;
            }
            else
            {
                printf("\nThat spot is invalid, try again: ");
                goto start;
            }
        }
        else
        {
            // top left open spot
            if (diagonal == 1 && board[row - 1][column - 1] == ' ')
            {
                // if the piece becomes a king at that instant
                if (row - 1 == 0)
                {
                    board[row - 1][column - 1] = 'o';
                    board[row][column] = ' ';
                    logic = false;
                }
                // not king at that instant
                else
                {
                    // already a king
                    if (board[row][column] == 'o')
                    {
                        board[row - 1][column - 1] = 'o';
                        board[row][column] = ' ';
                        logic = false;
                    }
                    // not a king at all
                    else
                    {
                        board[row - 1][column - 1] = 'O';
                        board[row][column] = ' ';
                        logic = false;
                    }
                }
            }
            // king bottom left open spot
            else if (diagonal == 3 && board[row + 1][column - 1] == ' ')
            {
                board[row + 1][column - 1] = 'o';
                board[row][column] = ' ';
                logic = false;
            }
            // top right open spot
            else if (diagonal == 2 && board[row - 1][column + 1] == ' ')
            {
                // if the piece becomes a king
                if (row - 1 == 0)
                {
                    board[row - 1][column + 1] = 'o';
                    board[row][column] = ' ';
                    logic = false;
                }
                // not king
                else
                {
                    // already a king
                    if (board[row][column] == 'o')
                    {
                        board[row - 1][column + 1] = 'o';
                        board[row][column] = ' ';
                        logic = false;
                    }
                    // not a king at all
                    else
                    {
                        board[row - 1][column + 1] = 'O';
                        board[row][column] = ' ';
                        logic = false;
                    }
                }
            }
            // bottom right open spot
            else if (diagonal == 4 && board[row + 1][column + 1] == ' ')
            {
                board[row + 1][column + 1] = 'o';
                board[row][column] = ' ';
                logic = false;
            }
            // can take opponent piece top left
            else if (diagonal == 1 && (board[row - 1][column - 1] == 'X' || board[row - 1][column - 1] == 'x'))
            {
                // space behind opponents diagonal is free and becomes a king at that instant
                if (board[row - 2][column - 2] == ' ' && row - 2 == 0)
                {
                    board[row - 2][column - 2] = 'o';
                    board[row - 1][column - 1] = ' ';
                    board[row][column] = ' ';
                    logic = false;
                }
                // space behind opponents diagonal is free and not king at that instant
                else if (board[row - 2][column - 2] == ' ')
                {
                    // if already a king
                    if (board[row][column] == 'o')
                    {
                        board[row - 2][column - 2] = 'o';
                        board[row - 1][column - 1] = ' ';
                        board[row][column] = ' ';
                        logic = false;
                    }
                    // not a king at that instant
                    else
                    {
                        board[row - 2][column - 2] = 'O';
                        board[row - 1][column - 1] = ' ';
                        board[row][column] = ' ';
                        logic = false;
                    }    
                }
            }
            // king can take opponent piece bottom left
            else if (diagonal == 3 && (board[row + 1][column - 1] == 'X' || board[row + 1][column - 1] == 'x'))
            {
                board[row + 2][column - 2] = 'o';
                board[row + 1][column - 1] = ' ';
                board[row][column] = ' ';
                logic = false;
            }
            // can take opponent piece top right
            else if (diagonal == 2 && (board[row - 1][column + 1] == 'X' || board[row - 1][column + 1] == 'x'))
            {
                if (board[row - 2][column + 2] == ' ' && row - 2 == 0)
                {
                    board[row - 2][column + 2] = 'o';
                    board[row - 1][column + 1] = ' ';
                    board[row][column] = ' ';
                    logic = false;
                }
                // space behind opponents diagonal is free at not king at that instant
                else if (board[row - 2][column + 2] == ' ')
                {
                    // if already a king
                    if (board[row][column] == 'o')
                    {
                        board[row - 2][column + 2] = 'o';
                        board[row - 1][column + 1] = ' ';
                        board[row][column] = ' ';
                        logic = false;
                    }
                    // not a king at that instant
                    else
                    {
                        board[row - 2][column + 2] = 'O';
                        board[row - 1][column + 1] = ' ';
                        board[row][column] = ' ';
                        logic = false;
                    }    
                }
            }
            // can take opponent piece bottom right
            else if (diagonal == 4 && (board[row + 1][column + 1] == 'X' || board[row + 1][column + 1] == 'x'))
            {
                board[row + 2][column + 2] = 'o';
                board[row + 1][column + 1] = ' ';
                board[row][column] = ' ';
                logic = false;
            }
            // if game fails

            
            else
            {
                printf("\nThat spot is invalid, try again: ");
                goto start;
            }
        }
    }    
}

void printBoard()
{
    int i, j;

    // column
    for (i = 0; i < 8; i++)
    {
        printf("   +---+---+---+---+---+---+---+---+\n");
        printf("%d  ", i + 1);
        printf("|");

        // rows
        for (j = 0; j < 8; j++)
        {
            printf(" ");
            printf("%c ", board[i][j]);
            printf("|");
        }

        printf("\n");
    }

    printf("   +---+---+---+---+---+---+---+---+\n");
    printf("     A   B   C   D   E   F   G   H\n\n");
}

void switchPlayer()
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

void checkWinner()
{
    int i, j;

    // counters to end game
    int counter_X = 0;
    int counter_O = 0;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'x')
            {
                counter_X++;
            }

            if (board[i][j] != 'O' && board[i][j] != 'o')
            {
                counter_O++;
            }
        }
    }

    if (counter_X == 64)
    {
        printf("\nGame over, player %c won!\n", turn[1]);
        exit(0);
    }
    if (counter_O == 64)
    {
        printf("\nGame over, player %c won!\n", turn[0]);
        exit(0);
    }
}