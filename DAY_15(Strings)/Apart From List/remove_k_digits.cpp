#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

string removeKdigits(string num, int k)
{

    if (k >= num.size())
        return "0";

    stack<char> s;

    for (int i = 0; i < num.size(); i++)
    {
        if (s.empty())
            s.push(num[i]);
        else
        {
            while (!s.empty() && s.top() > num[i] && k > 0)
            {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
    }

    while (k > 0)
    {
        s.pop();
        k--;
    }

    if (s.empty())
        return "0";

    string ans;
    while (!s.empty())
    {
        ans = s.top() + ans;
        s.pop();
    }

    int i = 0;
    while (ans[i] == '0')
    {
        i++;
    }

    return (ans.substr(i) == "") ? "0" : ans.substr(i);
}
int main()
{

    return 0;
}

// USING STACK
// https://leetcode.com/problems/remove-k-digits/
// https://youtu.be/hJnpt4_-DsI