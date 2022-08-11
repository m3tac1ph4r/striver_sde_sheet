#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

// 1. Recursion
int solve(int k, vector<int> &num, int target)
{
    if (target == 0)
        return 0;
    if (target < 0)
        return INT_MAX;
    int mini = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        int ans = solve(k, num, target - num[i]);
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans);
    }
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    int k = num.size();
    int ans = solve(k, num, x);
    if (ans == INT_MAX)
        return -1;
    return ans;
}

// 2. Memoization
int solve(vector<int> &coins, int amount, vector<int> &dp)
{
    if (amount == 0)
        return 0;
    else if (dp[amount] != -1)
        return dp[amount];
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans;
        if (amount >= coins[i])
        {
            ans = solve(coins, amount - coins[i], dp);
            if (ans != INT_MAX)
                mini = min(mini, 1 + ans);
        }
    }
    return dp[amount] = mini;
}
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, -1);
    int ans = solve(coins, amount, dp);
    if (ans != INT_MAX)
        return ans;
    return -1;
}

// 3. Tabulation
int minimumElements(vector<int> &num, int x)
{

    int k = num.size();
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    for (int tar = 1; tar <= x; tar++)
    {
        for (int j = 0; j < k; j++)
        {
            if (tar - num[j] >= 0 and dp[tar - num[j]] != INT_MAX)
            {
                dp[tar] = min(dp[tar], 1 + dp[tar - num[j]]);
            }
        }
    }
    if (dp[x] != INT_MAX)
        return dp[x];
    else
        return -1;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/coin-change/