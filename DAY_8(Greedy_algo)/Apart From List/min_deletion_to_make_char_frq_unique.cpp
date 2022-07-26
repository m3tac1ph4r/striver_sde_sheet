#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int minDeletions(string s)
{
    vector<int> frq(26, 0);

    for (int i = 0; i < s.length(); i++)
    {
        frq[s[i] - 'a']++;
    }

    sort(frq.begin(), frq.end(), greater<int>());

    int ans = 0, cuttOff = frq[0];
    for (int i = 0; i < frq.size(); i++)
    {
        if (frq[i] > cuttOff)
        {
            if (cuttOff > 0)
            {
                ans += frq[i] - cuttOff;
            }
            else
                ans += frq[i];
        }
        cuttOff = min(frq[i] - 1, cuttOff - 1);
    }
    return ans;
}
int main()
{

    return 0;
}

// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/