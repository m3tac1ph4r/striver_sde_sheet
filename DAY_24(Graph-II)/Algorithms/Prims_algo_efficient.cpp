#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;
    // first int-u second int-v third int-w

    // creating adjacency list
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // create vectors
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // first int - key[i]  and second int - i
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        // finding minimum element in key
        int u = pq.top().second;
        mst[u] = true;
        pq.pop();
        for (auto neighbour : adj[u])
        {
            int v = neighbour.first;
            int w = neighbour.second;

            if (mst[v] == false and w < key[v])
            {
                parent[v] = u;
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }
    vector<pair<pair<int, int>, int>> res;
    for (int i = 2; i <= n; i++)
    {
        res.push_back({{parent[i], i}, key[i]});
    }
    return res;
}

int main()
{

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/1095633
// TC : greater than O(nlogn)