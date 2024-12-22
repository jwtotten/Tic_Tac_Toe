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

    while(winner  == ' ' && checkFreeSpaces())
    {
        resetBoard();
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

}
void playerMove()
{

}
void computerMove()
{

}
char checkWinner()
{

}
void printWinner(char winner)
{

}
