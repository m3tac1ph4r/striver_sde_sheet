#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

void dfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;
    for (auto i : adj[node])
    {
        if (!visited[i])
            dfs(i, adj, visited, component);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;
    vector<bool> visited(V + 1, false);

    vector<vector<int>> ans;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, adj, visited, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main()
{

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462

// https://youtu.be/uDWljP2PGmU?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// https://youtu.be/aJa3U-hydXc?list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA