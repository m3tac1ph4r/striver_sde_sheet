#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

string longestCommonPrefix(vector<string> &strs)
{
    int min_len = INT_MAX, pos;
    for (int i = 0; i < strs.size(); i++)
    {
        int l = strs[i].length();
        if (l < min_len)
        {
            min_len = l;
            pos = i;
        }
    }
    string temp = strs[pos];
    int count = 0;
    for (int i = 0; i < temp.length(); i++)
    {
        char ch = temp[i];
        bool check = true;
        for (int j = 0; j < strs.size(); j++)
        {
            string temp2 = strs[j];
            if (ch != temp2[i])
            {
                check = false;
                break;
            }
        }
        if (check == true)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    return temp.substr(0, count);
}
int main()
{
    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i = 0; i < n; i++)
        cin >> strs[i];
    string ans = longestCommonPrefix(strs);
    cout << ans;
    return 0;
}

/*
https://leetcode.com/problems/longest-common-prefix/
*/