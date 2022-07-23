#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

bool solve(int i, int j, vector<vector<int>> &grid, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false; // invalid condition
    if (grid[i][j] == 1 || grid[i][j] == 2)
        return true; // if grid[i][j] is water or grid[i][j] is already visited

    grid[i][j] = 2;
    bool top = solve(i + 1, j, grid, n, m);
    bool bottom = solve(i - 1, j, grid, n, m);
    bool left = solve(i, j - 1, grid, n, m);
    bool right = solve(i, j + 1, grid, n, m);

    return top and bottom and left and right;
}
int closedIsland(vector<vector<int>> &grid)
{
    int count = 0;
    int n = grid.size();
    int m = grid[0].size();
    // will start a loop from 1 to n-1 bcz boundary elements will not be considered
    for (int i = 1; i < n - 1; i++)
    {
        // will start a loop from 1 to m-1 bcz boundary elements will not be considered
        for (int j = 1; j < m - 1; j++)
        {
            if (grid[i][j] == 0)
            {
                if (solve(i, j, grid, n, m))
                    count++;
            }
        }
    }
    return count;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/number-of-closed-islands/
// USING DFS