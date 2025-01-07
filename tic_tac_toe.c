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
char checkWinNextMove(char, char);
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

        playerMove();
        winner = checkWinner();

        if(winner != ' ' || checkFreeSpaces() == 0)
        {   
            printBoard();
            printWinner(winner);
            break;
        }

        computerMove();
        winner = checkWinner();

        if(winner != ' ' || checkFreeSpaces() == 0)
        {
            printBoard();
            printWinner(winner);
            break;
        }
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
        printf(" %c | %c | %c ", board[k][0], board[k][1], board[k][2]);
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

    srand(time(0));
    int x;
    int y;

    if(checkFreeSpaces() > 0)
    {
        // check if the computer can win and then win the game, aslso check if player can win and block them.
        if (checkWinNextMove(COMPUTER, COMPUTER) == ' ' && checkWinNextMove(PLAYER, COMPUTER) == ' ') 
        {
            do{
                x = rand() % 3;
                y = rand() % 3;
            } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
        } 
    }
}

char checkWinNextMove(char value, char computer)
{
    // Rows
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == value && board[i][1] == value && board[i][2] == ' ')
        {
            board[i][2] = computer;
            return computer;
        }
        else if(board[i][0] == value && board[i][2] == value && board[i][1] == ' ')
        {
            board[i][1] = computer;
            return computer;
        }
        else if(board[i][1] == value && board[i][2] == value && board[i][0] == ' ')
        {
            board[i][0] = computer;
            return computer;
        }
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if(board[0][i] == value && board[1][i] == value && board[2][i] == ' ')
        {
            board[2][i] = computer;
            return computer;
        }
        else if(board[0][i] == value && board[2][i] == value && board[1][i] == ' ')
        {
            board[1][i] = computer;
            return computer;
        }
        else if(board[1][i] == value && board[2][i] == value && board[0][i] == ' ')
        {
            board[0][i] = computer;
            return computer;
        }
    }

    // Diagonals
    if(board[0][0] == value && board[1][1] == value && board[2][2] == ' ')
    {
        board[2][2] = computer;
        return computer;
    }
    else if(board[0][0] == value && board[2][2] == value && board[1][1] == ' ')
    {
        board[1][1] = computer;
        return computer;
    }
    else if(board[1][1] == value && board[2][2] == value && board[0][0] == ' ')
    {
        board[0][0] = computer;
        return computer;
    }

    if(board[0][2] == value && board[1][1] == value && board[2][0] == ' ')
    {
        board[2][0] = computer;
        return computer;
    }
    else if(board[0][0] == value && board[2][0] == value && board[0][2] == ' ')
    {
        board[0][2] = computer;
        return computer;
    }
    else if(board[0][2] == value && board[2][0] == value && board[1][1] == ' ')
    {
        board[1][1] = computer;
        return computer;
    }

    return ' ';
}

char checkWinner()
{
    // Rows
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    // Diagonals  
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';
}

void printWinner(char winner)
{
    if(winner == PLAYER)
    {
        printf("Player wins!");
    }
    else if(winner == COMPUTER)
    {
        printf("Computer wins!");
    }
    else
    {
        printf("It's a tie!");
    }
}
