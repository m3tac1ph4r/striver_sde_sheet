#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

void dfs(int i, unordered_map<int, list<int>> adj, vector<bool> &visited)
{
    visited[i] = true;
    for (auto it : adj[i])
    {
        if (!visited[it])
        {
            dfs(it, adj, visited);
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<bool> visited(n, false);
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < isConnected[i].size(); j++)
        {
            if (i == j)
                continue;
            else if (isConnected[i][j] == 1)
                adj[i].push_back(j);
        }
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited);
            c++;
        }
    }
    return c;
}

int main()
{

    return 0;
}

// In this question we have to count the number of components of graph
// https://leetcode.com/problems/number-of-provinces/