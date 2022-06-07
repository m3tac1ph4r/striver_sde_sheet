#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

void makeAdjList(unordered_map<int, list<int>> &adj, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int>> adj;
    makeAdjList(adj, edges);

    vector<int> visited(vertex, 0);
    vector<int> ans;
    // this is when you are getting TLE
    // for (int i = 0; i < vertex; i++)
    //     adj[i].sort();
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                ans.push_back(node);
                q.pop();
                for (auto j : adj[node])
                {
                    if (!visited[j])
                    {
                        q.push(j);
                        visited[j] = 1;
                    }
                }
            }
        }
    }
    return ans;
}
int main()
{

    return 0;
}