#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

// 1. Memoization
int solve(int i, int W, vector<int> &values, vector<int> &weights, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (W >= weights[i])
            return values[i];
        else
            return 0;
    }
    else if (dp[i][W] != -1)
        return dp[i][W];
    int pick = 0;
    if (W >= weights[i])
    {
        pick = values[i] + solve(i - 1, W - weights[i], values, weights, dp);
    }
    int nonpick = solve(i - 1, W, values, weights, dp);
    return dp[i][W] = max(pick, nonpick);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return solve(n - 1, w, values, weights, dp);
}

// 2. Tabulation
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    // base case
    for (int i = weights[0]; i <= w; i++)
        dp[0][i] = values[0];

    for (int i = 1; i < n; i++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int pick = 0;
            if (wt >= weights[i])
                pick = values[i] + dp[i - 1][wt - weights[i]];
            int nonpick = dp[i - 1][wt];
            dp[i][wt] = max(pick, nonpick);
        }
    }
    return dp[n - 1][w];
}
int main()
{

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/1072980