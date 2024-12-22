#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = '0';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);


// This is the main loop that is executed when the c file is made.
int main()
{
    char winner = ' ';

    resetBoard();

    while(winner  == ' ' && checkFreeSpaces() != 0)
    {
        printBoard();
    }

    return 0;
}


void resetBoard()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }

}
void printBoard()
{
    for(int k = 0; k < 3; k++)
    {
        printf("   |   |   ");
        printf(" %c | %c | %c ", board[k][0], board[k][1], board[k][2]);
        printf("   |   |   ");
        printf("\n---|---|---\n");
    }
}
int checkFreeSpaces()
{
    int freeSpaces = 9;
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }

    return freeSpaces;
}
void playerMove()
{
    int x;
    int y;

    do
    {
        printf("Enter row number (1-3): ");
        scanf("%d", &x);
        x--;

        printf("Enter column number (1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' ')
        {
            printf("Invalid move");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
    

}
void computerMove()
{

}
char checkWinner()
{
    // Placeholder implementation
    return ' ';
}
void printWinner(char winner)
{

}
