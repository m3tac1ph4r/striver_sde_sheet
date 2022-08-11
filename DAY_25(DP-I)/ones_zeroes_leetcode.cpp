#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

// MEMOIZATION
int solve(int i, vector<string> &strs, int m, int n, vector<pair<int, int>> &adj, vector<vector<vector<int>>> &dp)
{
    auto out = adj[i];
    int c0 = out.first;
    int c1 = out.second;
    if (i == 0)
    {
        if (m >= c0 and n >= c1)
            return 1;
        else
            return 0;
    }
    else if (dp[i][m][n] != -1)
        return dp[i][m][n];
    int pick = 0;
    if (m >= c0 and n >= c1)
        pick = 1 + solve(i - 1, strs, m - c0, n - c1, adj, dp);
    int nonpick = solve(i - 1, strs, m, n, adj, dp);
    return dp[i][m][n] = max(pick, nonpick);
}
int findMaxForm(vector<string> &strs, int m, int n)
{
    int l = strs.size();
    vector<pair<int, int>> adj;
    for (int i = 0; i < l; i++)
    {
        int c0 = 0, c1 = 0;
        for (char ch : strs[i])
        {
            if (ch == '0')
                c0++;
            else
                c1++;
        }
        adj.push_back({c0, c1});
    }

    vector<vector<vector<int>>> dp(l, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
    return solve(l - 1, strs, m, n, adj, dp);
}
int main()
{

    return 0;
}

// https://leetcode.com/problems/ones-and-zeroes/