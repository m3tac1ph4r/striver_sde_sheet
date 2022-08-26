#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        unordered_map<char, int> mp;
        int n = s.length();
        int left = 0, ans = 0;
        unordered_set<char> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(s[i]);
        }
        if (st.size() < k)
            return -1;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            if (mp.size() > k)
            {
                while (mp[s[left]] > 0 and left < i)
                {
                    mp[s[left]]--;
                    if (mp[s[left]] == 0)
                    {
                        mp.erase(s[left]);
                        left++;
                        break;
                    }
                    left++;
                }
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};

int main()
{

    return 0;
}

// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853