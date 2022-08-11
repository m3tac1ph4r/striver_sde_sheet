#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int minSwaps(vector<int> &nums)
{
    // Code here
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]] = i;
    }
    int ans = 0;
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == temp[i])
            continue;
        else
        {
            ans++;
            int sortIndex = mp[temp[i]];
            int unsortIndex = i;
            int ele = nums[i];
            nums[i] = temp[i];
            nums[sortIndex] = ele;
            mp[nums[i]] = i;
            mp[ele] = sortIndex;
        }
    }
    return ans;
}

int main()
{

    return 0;
}

// https://practice.geeksforgeeks.org/problems/minimum-swaps/1