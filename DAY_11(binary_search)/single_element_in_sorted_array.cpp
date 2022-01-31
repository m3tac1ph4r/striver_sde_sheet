#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

/*
Using Binary Search
*/
int singleNonDuplicate(vector<int> &nums) 
{
    int low=0,high=nums.size()-2;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(mid%2==0)    // check whether it is left array or not
        {
            if(nums[mid]!=nums[mid+1])
            {
                high=mid-1;
            }
            else
                low=mid+1;
        }
        else
        {
            if(nums[mid]==nums[mid+1])    // check whether it is right array or not
                high=mid-1;
            else
                low=mid+1;   
        }
        
    }
    return nums[low];
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    cout<<singleNonDuplicate(nums);   
    return 0;
}

/*
https://leetcode.com/problems/single-element-in-a-sorted-array/
*/

/*
Naive Approch:
nums - 1 1 2 2 3
index- 0 1 2 3 4

As you can see the first occurence of number is coming in even index from left to right array until single element.
Same in right to left array also.

int singleNonDuplicate(vector<int> &nums)
{
    int ele;
    if (nums.size() == 1)
        return nums[0];
    for (int i = 0; i < nums.size() - 2; i = i + 2)
    {
        if (i < nums.size() and nums[i] != nums[i + 1])
        {
            ele = nums[i];
            break;
        }
    }
    for (int j = nums.size() - 1; j >= 2; j = j - 2)
    {
        if (nums[j] != nums[j - 1])
        {
            ele = nums[j];
            break;
        }
    }
    return ele;
}
*/

/*
Using XOR funtion:
Two basic properties of XOR
p^p=0
0^p=p

int singleNonDuplicate(vector<int>& nums) {
    int ans=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        ans=ans^nums[i];
    }
        return ans;
}


INPUT: [1,1,2,3,3,4,4,8,8]

1^1 = 0
0^2 = 2
2^3 = 2
...
*/