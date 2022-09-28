#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

// 1. Recursion
class Solution
{
public:
    int solve(int i, int j, string word1, string word2)
    {
        if (i < 0)
            return j + 1;
        else if (j < 0)
            return i + 1;

        if (word1[i] == word2[j])
            return solve(i - 1, j - 1, word1, word2);
        else
        {
            int insert = 1 + solve(i, j - 1, word1, word2);
            int replace = 1 + solve(i - 1, j - 1, word1, word2);
            int del = 1 + solve(i - 1, j, word1, word2);

            return min(insert, min(replace, del));
        }
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        return solve(n - 1, m - 1, word1, word2);
    }
};

// 2. Memoization
class Solution
{
public:
    int solve(int i, int j, string word1, string word2, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;
        else if (j < 0)
            return i + 1;
        else if (dp[i][j] != -1)
            return dp[i][j];
        if (word1[i] == word2[j])
            return solve(i - 1, j - 1, word1, word2, dp);
        else
        {
            int insert = 1 + solve(i, j - 1, word1, word2, dp);
            int replace = 1 + solve(i - 1, j - 1, word1, word2, dp);
            int del = 1 + solve(i - 1, j, word1, word2, dp);

            return dp[i][j] = min(insert, min(replace, del));
        }
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, word1, word2, dp);
    }
};

// 3. Tabulation
class Solution
{
public:
    int solve(int n, int m, string word1, string word2, vector<vector<int>> &dp)
    {
        int insert, del, replace;
        // base case
        for (int j = 0; j <= m; j++)
            dp[0][j] = j; // Not adding 1 bcz now we are doing 1 based indexing

        for (int i = 0; i <= n; i++)
            dp[i][0] = i; // Not adding 1 bcz now we are doing 1 based indexing

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    insert = 1 + dp[i][j - 1];
                    replace = 1 + dp[i - 1][j - 1];
                    del = 1 + dp[i - 1][j];
                    dp[i][j] = min(insert, min(replace, del));
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        return solve(n, m, word1, word2, dp);
    }
};

int main()
{

    return 0;
}

// https://leetcode.com/problems/edit-distance/