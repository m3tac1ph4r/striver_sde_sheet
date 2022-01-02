#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

int majorityElement(vector<int> &nums)
{
    sort(nums.begin(),nums.end());
    return nums[nums.size()/2];
}  
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    cout<<majorityElement(nums);
    return 0;
}

/*
Code Link : https://leetcode.com/problems/majority-element/
*/