#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

bool checkPalindrome(string s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}
void solve(string s, vector<string> &temp, vector<vector<string>> &ans)
{
    if (s.length() == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        string subString = s.substr(0, i + 1);
        if (checkPalindrome(subString))
        {
            temp.push_back(subString);
            solve(s.substr(i + 1), temp, ans);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> temp;
    solve(s, temp, ans);
    return ans;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/palindrome-partitioning/
// https://youtu.be/pkBG7lB-1N8