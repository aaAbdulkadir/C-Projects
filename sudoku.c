#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

/* ------------------ GLOBAL VARIABLES ------------------ */
int board[9][9] = {{0, 2, 0, 0, 0, 4, 3, 0, 0}, 
                   {9, 0, 0, 0, 2, 0, 0, 0, 8}, 
                   {0, 0, 0, 6, 0, 9, 0, 5, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 1},
                   {0, 7, 2, 5, 0, 3, 6, 8, 0},
                   {6, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 8, 0, 3, 0, 5, 0, 0, 0},
                   {1, 0, 0, 0, 9, 0, 0, 0, 3},
                   {0, 9, 8, 0, 0, 0, 0, 6, 0}};

// rows and columns
int r, c;

/* ------------------ DECLARE FUNCTIONS ------------------ */

void printBoard();
void puzzle();
void checkForWin();

/* ------------------ MAIN ------------------ */

int main(void)
{
    // intro
    printf("\n===============================================================================\n");
    printf("*************************************SUDOKU************************************\n");
    printf("===============================================================================\n");
    printf("\n\n");
    sleep(1);
    printf("Fill in the sudoku board and once finished you will found out whether your \nsolution is correct\n\n");
    sleep(3);   
    printf("SOLVE THE FOLLOWING BOARD, WHERE THE ZEROS ARE EMPTY SPOTS.\n\n");
    sleep(1);
    printBoard();
    printf("\n");

    for (int i = 0; i < 55; i++)
    {
        printf("\n");

        // place
        puzzle();

        printf("\n");

        // print board
        printBoard();
    }
}

/* ------------------ FUNCTIONS ------------------ */

// ask user for position they want to input the number into
void puzzle()
{
    int number;
    bool isTrue = true;

    while (isTrue == true)
    {
        // row placement
        printf("Row: ");
        scanf("%d", &r);

        if ((r > 9) || (r < 1))
        {
            printf("Pick a number within the range 1-9 of the 9 x 9 grid... ");
            continue;
        }

        // column placement
        printf("Column: ");
        scanf("%d", &c);

        if ((c > 9) || (c < 1))
        {
            printf("Pick a number within the range 1-9 of the 9 x 9 grid: ");
            continue;
        }

        // check if row column placement is free
        if (board[r - 1][c - 1] != 0)
        {
            printf("That spot is taken, input an empty spot: ");
            continue;
        }

        // get user input for the number they want to put in that position
        printf("What number do you want to put in that position (1-9): ");

        scanf("%d", &number);

        if ((number > 9) || (number < 1))
        {
            printf("Pick a number within the range 1-9: ");
            continue;
        }

        isTrue = false;
    } 
    
    // update board for new position
    board[r - 1][c - 1] = number;    
}

// print the board at its current state
void printBoard()
{
    int i, j, k;

    // numbers above top border for column positioning
    printf("   ");

    for (k = 0; k < 3; k++)
    {
        printf(" %d ", k + 1);
    }

    printf(" ");

    for (k = 3; k < 6; k++)
    {
        printf(" %d ", k + 1);
    }

    printf(" ");

    for (k = 6; k < 9; k++)
    {
        printf(" %d ", k + 1);
    }

    printf("\n");

    // nested loop to print board
    for (i = 0; i < 9; i++)
    {

        // make top border for numbers
        if (i == 0)
        {
            printf("  +-----------------------------+\n");
        }

        for (j = 0; j < 9; j++)
        {
            // print horizontal border for numbers
            if (j == 0)
            {
                printf("%d ", i + 1);

                printf("|");
            }
        
            printf(" %d ", board[i][j]);

            // input board formatting for columns
            if ((((j + 1) % 3) == 0) && (j != 8))
            {
                printf("|");
            }

            // print right border 
            if (j == 8)
            {
                printf("|");
            }
        }

        printf("\n");

        // input board formatting for rows
        if ((((i + 1) % 3) == 0) && (i != 8))
        {
            printf("  +---------+---------+---------+\n");
        }
        
        // make bottom border for numbers
        if (i == 8)
        {
            printf("  +-----------------------------+\n");
        }
    }
}

// check if all the positions on the board are filled in
void checkForWin()
{
    // unique solution
    if ((board[0][0] != 8) && (board[0][2] != 7) && (board[0][3] != 1) && (board[0][4] != 5) && (board[0][2] != 9) && (board[0][2] != 8) && 
        (board[1][1] != 6) && (board[2][1] != 5) && (board[3][1] != 3) && (board[5][1] != 7) && (board[6][1] != 1) && (board[7][1] != 4) &&
        (board[0][2] != 3) && (board[1][2] != 4) && (board[2][2] != 1) && (board[4][2] != 8) && (board[6][2] != 7) && (board[8][2] != 2) &&
        (board[0][3] != 5) && (board[1][3] != 9) && (board[2][3] != 3) && (board[3][3] != 4) && (board[4][3] != 6) && (board[5][3] != 8) && (board[6][3] != 2) && (board[7][3] != 7) &&
        (board[0][4] != 4) && (board[4][4] != 1) && (board[8][4] != 9) &&
        (board[1][5] != 1) && (board[2][5] != 8) && (board[3][5] != 9) && (board[4][5] != 7) && (board[5][5] != 2) && (board[6][5] != 4) && (board[7][5] != 3) && (board[8][5] != 5) &&
        (board[0][6] != 7) && (board[2][6] != 6) && (board[4][6] != 3) && (board[6][6] != 9) && (board[7][6] != 1) && (board[8][6] != 4) &&
        (board[1][7] != 5) && (board[2][7] != 4) && (board[3][7] != 7) && (board[5][7] != 6) && (board[6][7] != 8) && (board[7][7] != 2) &&
        (board[0][8] != 2) && (board[1][8] != 3) && (board[4][8] != 4) && (board[5][8] != 1) && (board[6][8] != 5) && (board[8][8] != 7))
        {
            printf("Incorrect solution, the correct solution is...\n\n");

            // solution
            printf("    1  2  3   4  5  6   7  8  9\n");
            printf("  +-----------------------------+\n");
            printf("1 | 8  2  7 | 1  5  4 | 3  9  6 |\n");
            printf("2 | 9  6  5 | 3  2  7 | 1  4  8 |\n");
            printf("3 | 3  4  1 | 6  8  9 | 7  5  2 |\n");
            printf("  +---------+---------+---------+\n");
            printf("4 | 5  9  3 | 4  6  8 | 2  7  1 |\n");
            printf("5 | 4  7  2 | 5  1  3 | 6  8  9 |\n");
            printf("6 | 6  1  8 | 9  7  2 | 4  3  5 |\n");
            printf("  +---------+---------+---------+\n");
            printf("7 | 7  8  6 | 2  3  5 | 9  1  4 |\n");
            printf("8 | 1  5  4 | 7  9  6 | 8  2  3 |\n");
            printf("9 | 2  3  9 | 8  4  1 | 5  6  7 |\n");
            printf("  +-----------------------------+\n");
            exit(0);
        }
        else
        {
            printf("Congratulations, you got the correct solution!\n");
            exit(0);
        }
}