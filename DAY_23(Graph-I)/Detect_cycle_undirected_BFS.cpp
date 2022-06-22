#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

bool check_cycle(int node, vector<bool> &visited, unordered_map<int, list<int>> &adj, unordered_map<int, int> parent)
{
    queue<int> q;
    visited[node] = true;
    parent[node] = -1; // because root does't have parent
    q.push(node);

    while (!q.empty())
    {
        int front_node = q.front();

        q.pop();

        for (auto it : adj[front_node])
        {
            if (!visited[it])
            {
                visited[it] = true;
                q.push(it);
                parent[it] = front_node;
            }

            else if (visited[it] == true and it != parent[front_node]) // means neighbour of it is already visited by another node
                return true;
        }
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
    unordered_map<int, int> parent;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = check_cycle(i, visited, adj, parent);
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

// https://www.codingninjas.com/codestudio/problems/1062670