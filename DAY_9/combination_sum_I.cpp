#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

void solve(int i,int n,vector<int> candidates,int target,vector<int> &temp,vector<vector<int>> &ans)
{
    if(i==n)
    {
        if(target==0)
            ans.push_back(temp);
    }
    else
    {
        if(candidates[i]<=target)
        {
            temp.push_back(candidates[i]);
            solve(i,n,candidates,target-candidates[i],temp,ans);
            temp.pop_back();
        }
        solve(i+1, n, candidates, target, temp, ans);
    }
    
}
vector<vector<int>> combinationSum(vector<int> candidates,int target)
{
    vector<int> temp;
    vector<vector<int>> ans;
    solve(0, candidates.size(), candidates, target, temp, ans);
    return ans;
}
int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> candidates(n);
    for(int i=0;i<n;i++)
        cin>>candidates[i];
    vector<vector<int>> ans=combinationSum(candidates,target);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j];
        cout << "],";
    }
    return 0;
}

/*
https://leetcode.com/problems/combination-sum/

Using PICK AND NON-PICK method
*/