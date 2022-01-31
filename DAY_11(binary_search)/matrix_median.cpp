#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
int findMedian(vector<vector<int>> &A)
{
    int startval=0;
    int endval=INT_MAX;
    int r=A.size();
    int c=A[0].size();
    int midval,ans;
    while (startval<=endval)
    {
        ans=0;
        midval=(startval+endval)/2;
        for(int i=0;i<r;i++)
        {
            int low=0,high=c-1;
            while (low<=high)
            {
                int m=low+(high-low)/2;
                if(A[i][m]<=midval)
                    low=m+1;
                else
                    high=m-1;
            }
            ans=ans+low;
        }
        if(ans<=(r*c)/2)
            startval=midval+1;
        else
            endval=midval-1;
    }
    return startval;
}    
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> A(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }
    cout<<findMedian(A);
    return 0;
}

/*
https://www.interviewbit.com/problems/matrix-median/#

Solved Using Binary Search

IF we have to find mid value in range like 10 to 2000 then formula used :
midvalue=(startvalue+endvalue)/2   i,e (10+2000)/2

But if we have to mid value of index like 0-3 then the formula is
m=low+(high-low)/2  i.e 0+(3-0)/2
*/