#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

class Solution
{
public:
    int atMost(vector<int> &nums, int k, int n)
    {
        int left = 0, right = 0, max_len = 0;
        unordered_map<int, int> mp;
        while (right < n)
        {
            mp[nums[right]]++;
            if (mp.size() > k)
            {
                while (mp.size() > k and left < right)
                {
                    mp[nums[left]]--;
                    if (mp[nums[left]] == 0)
                    {
                        mp.erase(mp[nums[left]]);
                        left++;
                        break;
                    }
                    left++;
                }
            }
            max_len += right - left + 1;
            right++;
        }
        return max_len;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans1 = atMost(nums, k, n);
        int ans2 = atMost(nums, k - 1, n);
        return ans1 - ans2;
    }
};

int main()
{

    return 0;
}

/*
1. Find number of subarrays with at most k different integers
2. Find number of subarrays with at most k-1 different integers
3. Now subtract (atmost k integer) - (atmost k-1 integer)
*/
// https://leetcode.com/problems/subarrays-with-k-different-integers/