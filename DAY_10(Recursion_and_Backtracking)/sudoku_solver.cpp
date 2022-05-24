#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

bool isValid(int row,int col,char c,vector<vector<char>> &board)
{
    for(int i=0;i<9;i++)
    {
        if(board[i][col]==c)    // for checking row
            return false;
        if(board[row][i]==c)    // for checking column
            return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)  // for 3x3 grid
            return false;
    }
    return true;
}
bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(i, j, c, board))
                    {
                        board[i][j] = c;
                        if (solve(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}
int main()
{
    vector<vector<char>> board = {{ '5', '3', '.', '.', '7', '.', '.', '.', '.' }, 
    { '6', '.', '.', '1', '9', '5', '.', '.', '.' }, 
    { '.', '9', '8', '.', '.', '.', '.', '6', '.' }, 
    { '8', '.', '.', '.', '6', '.', '.', '.', '3' }, 
    { '4', '.', '.', '8', '.', '3', '.', '.', '1' }, 
    { '7', '.', '.', '.', '2', '.', '.', '.', '6' }, 
    { '.', '6', '.', '.', '.', '.', '2', '8', '.' }, 
    { '.', '.', '.', '4', '1', '9', '.', '.', '5' }, 
    { '.', '.', '.', '.', '8', '.', '.', '7', '9' }};
    solveSudoku(board);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cout<<board[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}

/*
https://leetcode.com/problems/sudoku-solver/

Three Rules:
1. Every coloumn should have 1-9  digit once.
2. Every row should have 1-9 digit once.
3. Every 3x3 grid should have 1-9 digit once in a grid. 
*/