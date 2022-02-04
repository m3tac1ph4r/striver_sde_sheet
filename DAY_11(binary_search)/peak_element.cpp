#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
int findPeakElement(vector<int> nums)
{
    int low=0,high=nums.size()-1;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if(mid>0 and mid<nums.size()-1)
        {
            if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid-1]>nums[mid])
            {
                high=mid-1;
            }
            else if(nums[mid+1]>nums[mid])
                low=mid+1;
        }
        else if(mid==0)
        {
            if(nums[0]>nums[1])
                return 0;
            else
                return 1;
        }
        else if (mid == nums.size()-1)
        {
            if (nums[nums.size()-1]>nums[nums.size()-2])
                return nums.size()-1;
            else
                return nums.size()-2;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    cout<<findPeakElement(nums);
    return 0;
}

/*
https://leetcode.com/problems/peak-index-in-a-mountain-array/
https://leetcode.com/problems/find-peak-element/

*/