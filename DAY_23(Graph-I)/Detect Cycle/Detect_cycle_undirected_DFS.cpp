#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

bool DfsIsCyclic(int node, int parent, vector<bool> &visited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            // visited[it] = true;
            bool ans = DfsIsCyclic(it, node, visited, adj);
            if (ans == true)
                return true;
        }
        else if (visited[it] == true and it != parent)
            return true;
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // create an adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = DfsIsCyclic(i, -1, visited, adj);
            if (ans == true)
                return "Yes";
        }
    }
    return "No";
}

int main()
{

    return 0;
}