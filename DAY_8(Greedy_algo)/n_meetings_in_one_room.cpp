#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

static bool comp(vector<int> &a,vector<int> &b)
{
    // if(a[1]==b[1])
    //     return a[0]<b[0];
    return a[1]<b[1];
}
int maxMeetings(int start[],int end[],int n)
{
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({start[i],end[i]});
    }
    sort(v.begin(),v.end(),comp);   // Sort according to end time    
    int count=1;    //because last interval will never conincide with other interval so I count it first
    int j=1;
    int i=0;
    while (j<n)
    {
        if(v[i][1]<v[j][0])
        {
            i=j;
            j++;
            count++;
        }
        else
            j++;
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    int start[n];
    int end[n];
    for(int i=0;i<n;i++)
        cin>>start[i];
    for (int i = 0; i < n; i++)
        cin >> end[i];
    cout<<maxMeetings(start,end,n);
    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

Firstly sorted the vector according to end time. 
For example 
v: [1,2] [3,4] [0,6] [5,7] [8,9] [5,9]
Now check (2<3) if True then increase count and increase i to j and j to next interval
*/