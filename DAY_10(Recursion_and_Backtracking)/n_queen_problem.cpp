#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

bool isSafe(int row,int col,vector<string> board,int n)
{
    int duprow=row,dupcol=col;
    // LEFT UPPER DIAGONAL
    while(duprow>=0 and dupcol>=0)
    {
        if(board[duprow][dupcol]=='Q')
            return false;
        duprow--;dupcol--;
    }

    // LEFT ROW
    duprow=row;dupcol=col;
    while(dupcol>=0)
    {
        if(board[duprow][dupcol]=='Q')
            return false;
        dupcol--;
    }

    // LEFT LOWER DIAGONAL
    duprow=row;dupcol=col;
    while(duprow<n and dupcol>=0)
    {
        if(board[duprow][dupcol]=='Q')
            return false;
        duprow++;dupcol--;
    }
    return true;
}
void solve(int col,int n,vector<string> &board,vector<vector<string>> &ans)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }
    else
    {
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++)
        board[i]=s;
    solve(0,n,board,ans);
    return ans;
}    
int main()
{
    int n;
    cin>>n;
    vector<vector<string>> ans;
    ans=solveNQueens(n);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<n;j++)
            cout<<ans[i][j]<<"\n";
        cout<<"------------------"<<"\n";
    }
    return 0;
}
/*
https://leetcode.com/problems/n-queens/

Bruteforce approach

Time Complexity : O(n^3)
Space Complexity : O(n^2)
*/