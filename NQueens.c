#include <stdio.h>
#include <stdbool.h>
#define n 8
void printBoard(int b[n][n])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
             printf("%2c ", b[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
}
bool isSafe( int b[n][n],int row ,int col)
{

    int i, j;
    for (i = 0; i < col; i++)
        if (b[row][i] == 1)
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (b[i][j] == 1)
            return false;
    }
    for (i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (b[i][j] == 1)
            return false;
    }
    return true;
}
bool solveNQUtil(int board[n][n], int col)
{
    if (col == n)
    {
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}
bool solveNQueens(int board[n][n])
{
    if (!solveNQUtil(board, 0))
    {
        printf("Solution does not exist\n");
        printBoard(board);
        return false;
    }
    else
    {
        printf("The solution exists and the following are all its possible solutions:\n");
        printBoard(board);
    }
    return true;
}
int main()
{
    int board[n][n]={0};
    if (!solveNQueens(board))
    {
        printf("No solution exists for N = %d\n", n);
    }

    return 0;
}