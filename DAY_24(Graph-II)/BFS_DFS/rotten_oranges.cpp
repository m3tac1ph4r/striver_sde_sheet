#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int orangesRotting(vector<vector<int>> &grid)
{
    int min = 0, total_oranges = 0, count = 0;
    if (grid.size() == 0)
        return -1;
    queue<pair<int, int>> q;
    int r = grid.size(), c = grid[0].size();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] != 0)
                total_oranges++;
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }

    while (!q.empty())
    {
        int k = q.size();
        count += k;
        while (k--)
        {
            auto top_ele = q.front();
            q.pop();
            int i = top_ele.first;
            int j = top_ele.second;

            if (i - 1 >= 0 and grid[i - 1][j] == 1)
            {
                grid[i - 1][j] = 2;
                q.push({i - 1, j});
            }
            if (i + 1 < r and grid[i + 1][j] == 1)
            {
                grid[i + 1][j] = 2;
                q.push({i + 1, j});
            }
            if (j - 1 >= 0 and grid[i][j - 1] == 1)
            {
                grid[i][j - 1] = 2;
                q.push({i, j - 1});
            }
            if (j + 1 < c and grid[i][j + 1] == 1)
            {
                grid[i][j + 1] = 2;
                q.push({i, j + 1});
            }
            else
                continue;
        }
        if (!q.empty())
            min++;
    }

    if (total_oranges == count)
        return min;
    else
        return -1;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/rotting-oranges/
// https://youtu.be/pUAPcVlHLKA