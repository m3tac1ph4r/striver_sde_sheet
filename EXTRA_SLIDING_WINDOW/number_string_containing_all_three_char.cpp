#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        int last = n - 1;
        int left = 0, right = 0, ans = 0;
        unordered_map<char, int> mp;
        while (right < n)
        {
            mp[s[right]]++;
            while (mp['a'] >= 1 and mp['b'] >= 1 and mp['c'] >= 1)
            {
                ans += 1 + (last - right);
                mp[s[left]]--;
                left++;
            }
            right++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}

// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/