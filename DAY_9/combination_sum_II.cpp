#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

void solve(int i,int n,vector<int> candidates,int target,vector<int> &temp,vector<vector<int>> &ans)
{
    if(target==0)
    {
        ans.push_back(temp);
        return;
    }
    else
    {
        for(int ind=i;ind<n;ind++)
        {
            if(ind>i and candidates[ind]==candidates[ind-1])
                continue;
            if(candidates[ind]>target)
                break;
            temp.push_back(candidates[ind]);
            solve(ind+1,n,candidates,target-candidates[ind],temp,ans);
            temp.pop_back();
        }
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates,int target)
{
    sort(candidates.begin(),candidates.end());
    vector<int> temp;
    vector<vector<int>> ans;
    solve(0,candidates.size(),candidates,target,temp,ans);
    return ans;
}
int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> candidates(n);
    for(int i=0;i<n;i++)
        cin>>candidates[i];
    vector<vector<int>> ans=combinationSum2(candidates,target);
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
https://leetcode.com/problems/combination-sum-ii/
*/