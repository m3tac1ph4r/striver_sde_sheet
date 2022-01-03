#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

vector<int> majorityElement(vector<int> nums)
{
    int count1=0,count2=0,num1=-1,num2=-1,i;
    for(i=0;i<nums.size();i++)
    {
        if(nums[i]==num1)
            count1++;
        else if(nums[i]==num2)
            count2++;
        else if(count1==0)
        {
            num1=nums[i];
            count1++;
        }
        else if(count2==0)
        {
            num2=nums[i];
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    vector<int> ans;
    count1=count2=0;
    for(i=0;i<nums.size();i++)
    {
        if(nums[i]==num1)
            count1++;
        else if(nums[i]==num2)
            count2++;
    }
    if(count1>nums.size()/3)
        ans.push_back(num1);
    if(count2>nums.size()/3)
        ans.push_back(num2);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<int> ans=majorityElement(nums);
    for(int i:ans)
        cout<<i<<" ";
    return 0;
}


/*
Boyer-Moore Majority Voting Algorithm extended
*/