#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
bool isSafe(int x,int y,int n,vector<vector<int>> visited,vector<vector<int>> m)
{
    if(x>=0 and y>=0 and x<n and y<n and m[x][y]==1 and visited[x][y]==0)
        return true;
    else
        return false;
}
void solve(int x,int y,int n,string &s,vector<string> &ans,vector<vector<int>> m,vector<vector<int>> &visited)
{
    if(x==n-1 and y==n-1)   // base case
    {
        ans.push_back(s);
        return;
    }
    else
    {
        visited[x][y]=1;
        int newx,newy;
        //UP
        newx=x-1;newy=y;
        if(isSafe(newx,newy,n,visited,m))
        {
            s.push_back('U');
            solve(newx,newy,n,s,ans,m,visited);
            s.pop_back();   // backtracking step
        }
        
        // DOWN
        newx=x+1;newy=y;
        if (isSafe(newx, newy, n, visited, m))
        {
            s.push_back('D');
            solve(newx, newy, n, s, ans, m, visited);
            s.pop_back();   // backtracking step
        }

        // LEFT
        newx=x;newy=y-1;
        if (isSafe(newx, newy, n, visited, m))
        {
            s.push_back('L');
            solve(newx, newy, n, s, ans, m, visited);
            s.pop_back();   // backtracking step
        }

        // RIGHT
        newx=x;newy=y+1;
        if (isSafe(newx, newy, n, visited, m))
        {
            s.push_back('R');
            solve(newx, newy, n, s, ans, m, visited);
            s.pop_back();   // backtracking step
        }
        visited[x][y]=0;    // backtracking step
    }
    
}
vector<string> findPath(vector<vector<int>> m,int n)
{
    vector<vector<int>> visited(n,vector<int>(n,0));
    vector<string> ans;
    if(m[0][0]==0)
        return ans;
    int x=0,y=0;
    string s="";
    solve(x,y,n,s,ans,m,visited);
    return ans;
}    
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> m(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>m[i][j];
    }
    vector<string> ans=findPath(m,n);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<"\n";
    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

Solved Using Backtracking
*/