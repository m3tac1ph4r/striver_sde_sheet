#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

vector<int> countShortestDistance(vector<vector<int>> edges, int n, int m, int src)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> distance(n + 1, INT_MAX);
    vector<int> path(n + 1, 0);

    set<pair<int, int>> st;
    st.insert({0, 1});
    distance[1] = 0;
    path[1] = 1;

    while (!st.empty())
    {
        auto top = *(st.begin());
        st.erase(st.begin());
        int u = top.second;
        for (auto nbr : adj[u])
        {
            int v = nbr.first;
            int wt = nbr.second;
            if (distance[v] > distance[u] + wt)
            {
                auto findNode = st.find({distance[v], v});
                if (findNode != st.end())
                    st.erase(findNode);

                distance[v] = distance[u] + wt;
                path[v] = path[u];
                st.insert({distance[v], v});
            }
            else if (distance[v] == distance[u] + wt)
            {
                path[v] = path[u] + path[v];
            }
        }
    }
    return distance;
}
int main()
{
    int n = 6, m = 7;
    vector<vector<int>> edges(m);
    edges[0] = {1, 2, 3};
    edges[1] = {1, 3, 2};
    edges[2] = {2, 4, 2};
    edges[3] = {3, 5, 1};
    edges[4] = {5, 4, 2};
    edges[5] = {5, 6, 7};
    edges[6] = {4, 6, 1};
    vector<int> dist = countShortestDistance(edges, n, m, 1);
    for (auto i : dist)
        cout << i << " ";
    return 0;
}