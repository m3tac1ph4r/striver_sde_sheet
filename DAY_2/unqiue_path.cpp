#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

int findpath(int i,int j,int m,int n,vector<vector<int>> &dp)
{
    if(i==m-1 and j==n-1)
        return 1;
    else if(i>=m or j==n)
        return 0;
    else if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    else
    {
        return dp[i][j]=findpath(i+1,j,m,n,dp)+findpath(i,j+1,m,n,dp);
    }
}    
int uniquePaths(int m,int n)
{
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    int num=findpath(0,0,m,n,dp);
    if(m==1 and n==1)
        return num;
    else
        return dp[0][0];
}
int main()
{
    int m,n;
    cin>>m>>n;
    cout<<uniquePaths(m,n);
    return 0;
}

/*
The above question is solved using Dynamic Programming
https://leetcode.com/problems/unique-paths/
*/