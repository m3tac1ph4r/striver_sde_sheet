#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

int trap(vector<int> &height)
{
    int n=height.size();
    // the l[] will store maximum from 0 to n-1 and r[] will store maximum from n-1 to 0
    vector<int> l(n,0);
    vector<int> r(n,0);
    int volume=0,curr_max=0;
    for(int i=0;i<n;i++)
    {
        curr_max=max(curr_max,height[i]);
        r[i]=curr_max;
    }
    curr_max=0;
    for(int i=n-1;i>=0;i--)
    {
        curr_max=max(curr_max,height[i]);
        l[i]=curr_max;
    }
    for(int i=0;i<n;i++)
    {
        volume+=min(l[i],r[i])-height[i];
    }
    return volume;
}    
int main()
{
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i=0;i<n;i++)
        cin>>height[i];
    cout<<trap(height);
    return 0;
}

/*
https://leetcode.com/problems/trapping-rain-water/
*/