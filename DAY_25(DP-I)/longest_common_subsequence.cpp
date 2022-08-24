#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

// Recursion
class Solution
{
public:
    int solve(int i, int j, string text1, string text2)
    {
        if (i < 0 || j < 0)
            return 0;
        else if (text1[i] == text2[j]) // match case
            return 1 + solve(i - 1, j - 1, text1, text2);
        // not match
        return max(solve(i - 1, j, text1, text2), solve(i, j - 1, text1, text2));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();

        return solve(n - 1, m - 1, text1, text2);
    }
};

// Memoization
class Solution
{
public:
    int solve(int i, int j, string text1, string text2, vector<vector<int>> &dp)
    {
        if (i == 0 || j == 0)
            return 0;
        else if (dp[i][j] != -1)
            return dp[i][j];
        else if (text1[i - 1] == text2[j - 1]) // match case
            return dp[i][j] = 1 + solve(i - 1, j - 1, text1, text2, dp);
        // not match
        return dp[i][j] = max(solve(i - 1, j, text1, text2, dp), solve(i, j - 1, text1, text2, dp));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, text1, text2, dp);
    }
};

// Tabulation
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // base case
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};

int main()
{

    return 0;
}

// https://leetcode.com/problems/longest-common-subsequence/
// https://youtu.be/NPZn9jBrX8U?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY