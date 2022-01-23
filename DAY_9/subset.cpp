#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

void solve(int i, vector<int> nums, int n, vector<vector<int>> &ans, vector<int> &temp)
{
    if (i == n)
    {
        ans.push_back(temp);
    }
    else
    {
        temp.push_back(nums[i]);
        solve(i + 1, nums, n, ans, temp);
        temp.pop_back();
        solve(i + 1, nums, n, ans, temp);
    }
}
vector<vector<int>> subSets(vector<int> nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0, nums, nums.size(), ans, temp);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    vector<vector<int>> ans = subSets(nums);
    for(int i=0;i<ans.size();i++)
    {
        cout<<"[";
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j];
        cout<<"],";
    }
    return 0;
}