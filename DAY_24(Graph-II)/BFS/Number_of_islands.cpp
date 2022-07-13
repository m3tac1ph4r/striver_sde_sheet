#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

void markIslands(int i, int j, int r, int c, vector<vector<char>> &grid)
{
    grid[i][j] = '2';
    if (i - 1 >= 0 and grid[i - 1][j] == '1')
        markIslands(i - 1, j, r, c, grid);
    if (i + 1 < r and grid[i + 1][j] == '1')
        markIslands(i + 1, j, r, c, grid);
    if (j - 1 >= 0 and grid[i][j - 1] == '1')
        markIslands(i, j - 1, r, c, grid);
    if (j + 1 < c and grid[i][j + 1] == '1')
        markIslands(i, j + 1, r, c, grid);
}
int numIslands(vector<vector<char>> &grid)
{
    int res = 0;
    int r = grid.size();
    int c = grid[0].size();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == '1')
            {
                res++;
                markIslands(i, j, r, c, grid);
            }
        }
    }
    return res;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/number-of-islands/