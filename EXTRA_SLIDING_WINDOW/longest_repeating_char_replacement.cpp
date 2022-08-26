#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0, right = 0;
        int maxFrq = 0;
        int n = s.length();
        int maxLen = 0;
        map<char, int> mp;
        while (right < n)
        {
            mp[s[right]]++;
            maxFrq = max(maxFrq, mp[s[right]]);
            int currLen = right - left + 1;
            if (currLen - maxFrq > k)
            {
                mp[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};

int main()
{

    return 0;
}

// https://leetcode.com/problems/longest-repeating-character-replacement/