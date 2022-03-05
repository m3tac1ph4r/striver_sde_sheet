#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

void setZeroes(vector<vector<int>>& matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> rows(n,-1);
    vector<int> cols(m,-1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==0)
            {
                rows[i]=0;
                cols[j]=0;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(rows[i]==0 || cols[j]==0)
                matrix[i][j]=0;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>matrix[i][j];
    }
    setZeroes(matrix);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout<< matrix[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}

/*
https://leetcode.com/problems/set-matrix-zeroes/
*/