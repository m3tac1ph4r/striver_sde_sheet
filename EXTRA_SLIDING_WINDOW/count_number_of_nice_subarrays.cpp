#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
                nums[i] = 0;
            else
                nums[i] = 1;
        }
        // Now array would be [1,1,0,1,1] And now we will find the number of subrray
        // equal to sum k

        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0, sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end())
            {
                ans += mp[sum - k];
            }
            mp[sum]++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}

// https://leetcode.com/problems/count-number-of-nice-subarrays/
// https://youtu.be/atUJS7ArOY0