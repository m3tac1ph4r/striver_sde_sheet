#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

void solve(int ind,vector<int> &nums,vector<vector<int>> &ans)
{
    if(ind==nums.size())    // base function
    {
        ans.push_back(nums);
        return;
    }
    for(int i=ind;i<nums.size();i++)
    {
        swap(nums[i],nums[ind]);   
        solve(ind+1,nums,ans);      // recursive call
        swap(nums[i],nums[ind]);    // backtracking step
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    solve(0,nums,ans);
    return ans;
}    
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    vector<vector<int>> ans=permute(nums);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

/*
https://leetcode.com/problems/permutations/

Solved above question using recursion and backtracking
*/