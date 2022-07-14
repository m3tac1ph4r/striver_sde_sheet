#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

void dfs(int node, int parent, int &timer, vector<int> &discTime, vector<int> &lowTime, vector<vector<int>> &res, unordered_map<int, list<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    discTime[node] = lowTime[node] = timer++;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!visited[it])
        {
            dfs(it, node, timer, discTime, lowTime, res, adj, visited);
            lowTime[node] = min(lowTime[node], lowTime[it]);
            // check if edge is a bridge or not
            if (lowTime[it] > discTime[node])
            {
                vector<int> ans;
                ans.push_back(it);
                ans.push_back(node);
                res.push_back(ans);
            }
        }
        else
        {
            // means it is visited and not parent means it's a
            // back edge
            lowTime[node] = min(lowTime[node], discTime[it]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> discTime(v, -1);
    vector<int> lowTime(v, -1);
    vector<vector<int>> res;
    //     unordered_map<int,bool> visited;
    vector<bool> visited(v, false);
    int timer = 0, parent = -1;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, parent, timer, discTime, lowTime, res, adj, visited);
        }
    }
    return res;
}

int main()
{

    return 0;
}