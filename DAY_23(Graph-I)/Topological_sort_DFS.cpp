#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (!visited[it])
            topoSort(it, visited, s, adj);
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    vector<int> ans;
    vector<bool> visited(v, false);
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            topoSort(i, visited, s, adj);
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main()
{

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/982938