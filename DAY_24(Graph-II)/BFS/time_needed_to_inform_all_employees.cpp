#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    unordered_map<int, list<pair<int, int>>> adj;
    if (n == 1)
        return informTime[0];
    for (int i = 0; i < n; i++)
    {
        if (manager[i] == -1)
            continue;
        else
        {
            adj[manager[i]].push_back({i, informTime[i]});
        }
    }

    vector<int> distance(n, INT_MAX);
    queue<pair<int, int>> q;
    q.push({headID, informTime[headID]});
    distance[headID] = informTime[headID];
    while (!q.empty())
    {
        int id = q.front().first;
        q.pop();

        for (auto it : adj[id])
        {
            int v = it.first;
            int time = it.second;
            if (distance[id] + time < distance[v])
            {
                distance[v] = distance[id] + time;
                q.push({v, distance[v]});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (distance[i] != INT_MAX)
            ans = max(ans, distance[i]);
    }
    return ans;
}
int main()
{

    return 0;
}

// USING BFS
// https://leetcode.com/problems/time-needed-to-inform-all-employees/