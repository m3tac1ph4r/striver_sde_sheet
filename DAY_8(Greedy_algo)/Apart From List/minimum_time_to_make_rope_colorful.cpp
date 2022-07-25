#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int minCost(string colors, vector<int> &neededTime)
{
    char curr_ch = '*';
    int currTime = 0;
    int ans = 0;

    for (int i = 0; i < colors.length(); i++)
    {
        if (curr_ch == colors[i])
        {
            if (currTime < neededTime[i])
            {
                ans += currTime;
                currTime = neededTime[i];
            }
            else
            {
                ans += neededTime[i];
            }
        }
        else
        {
            curr_ch = colors[i];
            currTime = neededTime[i];
        }
    }
    return ans;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/