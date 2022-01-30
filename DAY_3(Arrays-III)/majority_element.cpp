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

Another Code (Using Moore's Voting Algorithm)

int majority(vector<int> nums)
{
    int count = 0;
    int candidate = 0;

    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
        }
        if (num == candidate)
            count += 1;
        else
            count -= 1;
    }
    return candidate;
}
*/