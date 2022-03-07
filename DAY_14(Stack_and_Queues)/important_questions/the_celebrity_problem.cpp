#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

bool knows(int a,int b)
{
    /* return true if a knows b otherwise false*/
}

int findCelebrity(int n)
{
    // Write your code here.
    stack<int> myStack;
    for (int i = 0; i < n; i++)
    {
        myStack.push(i);
    }
    while (myStack.size() > 1)
    {
        int a = myStack.top();
        myStack.pop();
        int b = myStack.top();
        myStack.pop();
        if (knows(a, b))
        {
            myStack.push(b);
        }
        else
            myStack.push(a);
    }
    int candidate = myStack.top();

    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (knows(candidate, i) == 0)
            zeroCount++;
    }
    if (zeroCount != n)
        return -1;
    int oneCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (knows(i, candidate) == 1 and candidate != i)
            oneCount++;
    }
    if (oneCount != n - 1)
        return -1;
    return candidate;
}

int main()
{
    
    return 0;
}

/*
https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1/#
*/

/*
BruteForece Approach:

int celebrity(vector<vector<int> >& M, int n) 
{
    // code here
    bool flag=false;
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        int r=0;
        for(int j=0;j<n;j++)
        {
            if(M[i][j]==0)
                r++;
        }
        if(r==n)
        {
            ans=i;
            break;
        }
    }
    int c=0;
    for(int j=0;j<n;j++)
    {
        if(M[j][ans]==1 and ans!=j)
            c++;
    }
    return (c==n-1)?ans:-1;
}
*/