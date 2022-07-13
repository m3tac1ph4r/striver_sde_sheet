#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

pair<int, int> findCoordinates(int sum, int n)
{
    int r = n - ((sum - 1) / n) - 1;
    int c = (sum - 1) % n;

    if (r % 2 == n % 2)        // since there is a reversal in cell position after every row,
        return {r, n - 1 - c}; // this check will take care of that
    else
        return {r, c};
}
int snakesAndLadders(vector<vector<int>> &board)
{
    queue<int> q;
    int n = board.size();
    int steps = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    q.push(1);
    visited[n - 1][0] = true;

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            int num = q.front();
            q.pop();

            if (num == n * n)
                return steps;

            for (int dice = 1; dice <= 6; dice++)
            {
                if (num + dice > n * n)
                    break;

                pair<int, int> coordinate = findCoordinates(num + dice, n);
                int r = coordinate.first;
                int c = coordinate.second;

                if (visited[r][c] == true)
                    continue;
                visited[r][c] = true;

                if (board[r][c] == -1)
                    q.push(num + dice);
                else
                    q.push(board[r][c]);
            }
        }
        steps++;
    }
    return -1;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/snakes-and-ladders/
// https://youtu.be/zWS2fCJGxmU