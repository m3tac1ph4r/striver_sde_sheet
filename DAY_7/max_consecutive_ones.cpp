#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int &i:nums)
        cin>>i;
    int max_one=0,curr=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==1)
            curr++;
        else
        {
            max_one=max(curr,max_one);
            curr=0;
        }
    }
    max_one=max(curr,max_one);
    cout<<max_one<<"\n";
    return 0;
}

/*
https://leetcode.com/problems/max-consecutive-ones/
*/