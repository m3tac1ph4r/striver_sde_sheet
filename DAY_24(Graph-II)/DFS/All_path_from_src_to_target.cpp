#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

void solve(int node, int n, unordered_map<int, list<int>> &adj, vector<int> temp, vector<vector<int>> &ans)
{
    if (node == n - 1)
    {
        temp.push_back(node);
        ans.push_back(temp);
        return;
    }

    temp.push_back(node);
    for (auto it : adj[node])
    {
        solve(it, n, adj, temp, ans);
    }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>> ans;

    unordered_map<int, list<int>> adj;
    int n = graph.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            int v = graph[i][j];
            adj[i].push_back(v);
        }
    }

    vector<int> temp;
    solve(0, n, adj, temp, ans);
    return ans;
}
int main()
{

    return 0;
}