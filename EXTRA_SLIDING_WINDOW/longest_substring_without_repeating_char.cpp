#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> st;
        int l = 0, max_len = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (st.find(s[i]) != st.end())
            {
                while (l < i and st.find(s[i]) != st.end())
                {
                    st.erase(s[l]);
                    l++;
                }
            }
            st.insert(s[i]);
            max_len = max(max_len, i - l + 1);
        }
        return max_len;
    }
};
int main()
{

    return 0;
}

// https://leetcode.com/problems/longest-substring-without-repeating-characters/