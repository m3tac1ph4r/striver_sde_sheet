#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0, right = 0;
        int ans = 0, zeroCount = 0;
        while (left <= right and right < nums.size())
        {
            if (nums[right] == 0)
                zeroCount++;
            while (zeroCount > k)
            {
                if (nums[left] == 0)
                    zeroCount--;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}

// https://leetcode.com/problems/max-consecutive-ones-iii/