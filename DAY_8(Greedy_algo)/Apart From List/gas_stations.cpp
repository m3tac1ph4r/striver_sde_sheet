#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int deficit = 0; // kami
    int balance = 0;
    int start = 0;
    int n = gas.size();
    for (int i = 0; i < n; i++)
    {
        balance += gas[i] - cost[i];
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (deficit + balance >= 0)
        return start;
    else
        return -1;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/gas-station/