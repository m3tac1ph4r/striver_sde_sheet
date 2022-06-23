#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

bool dfsCyclic(int node, vector<bool> &bag, vector<bool> &visited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    bag[node] = true;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            bool ans = dfsCyclic(it, bag, visited, adj);
            if (ans == true)
                return true;
        }
        else if (bag[it] == true)
            return true; // means it is already visited and also there in the bag. means cycle is present
    }
    bag[node] = false; // removing the node from the bag
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    vector<bool> visited(n + 1, false);
    vector<bool> bag(n + 1, false);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool ans = dfsCyclic(i, bag, visited, adj);
            if (ans == true)
                return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/course-schedule/

// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626
