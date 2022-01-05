#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

vector<int> twoSum(vector<int> &nums,int target)
{
    vector<int> ans(2);
    vector<int> tmp(nums.size());
    tmp=nums;
    sort(tmp.begin(),tmp.end());
    int i=0,j=tmp.size()-1;
    while(i<j and i<tmp.size())
    {
        if(tmp[i]+tmp[j]==target)
            break;
        else if(tmp[i]+tmp[j]>target)
            j--;
        else
        {
            i++;
            j=tmp.size()-1;
        }
    }
    bool check_i=false,check_j=false;
    for(int k=0;k<nums.size();k++)
    {
        if(nums[k]==tmp[i] and check_i==false)
        {
            ans[0]=k;
            check_i=true;
        }
        else if(nums[k]==tmp[j] and check_j==false)
        {
            ans[1]=k;
            check_j=true;
        }

    }
    return ans;
}   
int main()
{
    int n,target;
    cin>>n;
    vector<int> nums(n);
    for(int &i:nums)
        cin>>i;
    cin>>target;
    vector<int> ans=twoSum(nums,target);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}

/*
Similar to Sliding window technique
*/