#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

void solve(int indx, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans)
{
    ans.push_back(temp);
    for (int i = indx; i < nums.size(); i++)
    {
        if (i != indx and nums[i] == nums[i - 1])
            continue;
        temp.push_back(nums[i]);
        solve(i + 1, nums, temp, ans);
        temp.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int i = 0;
    sort(nums.begin(), nums.end());
    solve(i, nums, temp, ans);
    return ans;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/subsets-ii/
// https://youtu.be/RIn3gOkbhQE