#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

void findTopoSort(int node, vector<bool> &visited, stack<int> &st, vector<pair<int, int>> adj[])
{
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (!visited[it.first])
            findTopoSort(it.first, visited, st, adj);
    }

    st.push(node);
}
void shortestPath(int src, int N, vector<pair<int, int>> adj[])
{
    stack<int> st;
    vector<bool> visited(N, false);
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
            findTopoSort(i, visited, st, adj);
    }
    vector<int> dist(N, INT_MAX);
    dist[src] = 0;

    while (!st.empty())
    {
        int top_node = st.top();
        st.pop();
        if (dist[top_node] != INT_MAX)
        {
            for (auto it : adj[top_node])
            {
                dist[it.first] = min(dist[top_node] + it.second, dist[it.first]);
            }
        }
    }
    for (auto i : dist)
    {
        (i == INT_MAX) ? cout << "INF " : cout << i << " ";
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    shortestPath(0, n, adj);

    return 0;
}

// https://youtu.be/CrxG4WJotgg?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw