#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

vector<vector<int>> fourSum(vector<int> &nums,int target)
{
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int target2=target-nums[i]-nums[j];
            int l=j+1,k=n-1;
            while (l<k)
            {
                int sum=nums[l]+nums[k];
                if(sum<target2)
                    l++;
                else if(sum>target2)
                    k--;
                else
                {
                    vector<int> tmp(4);
                    tmp[0]=nums[i];
                    tmp[1]=nums[j];
                    tmp[2]=nums[l];
                    tmp[3]=nums[k];
                    ans.push_back(tmp);
                    // remove the duplicates of num[l]
                    while(l<k and nums[l]==tmp[2])
                        l++;
                    // remove the duplicates of num[k]
                    while(l<k and nums[k]==tmp[3])
                        k--;
                }
            }
            // remove the duplicates of num[j]
            while (j + 1 < n and nums[j] == nums[j + 1])
                j++;
        }
        // remove the duplicates of num[i]
        while(i+1<n and nums[i]==nums[i+1])
            i++;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int &i:nums)
        cin>>i;
    int target;
    cin >> target;
    vector<vector<int>> ans=fourSum(nums,target);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}

/*
Example:
NUMS = [1 0 -1 0 -2 2 0]
TARGET = 0

[[-2 -1 1 2 ],[-2 0 0 2 ],[-1 0 0 1 ]]
*/