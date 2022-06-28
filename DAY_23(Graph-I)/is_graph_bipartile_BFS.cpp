#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

bool isBipartite(vector<vector<int>> &graph)
{
    queue<int> q;
    unordered_map<int, list<int>> adj;
    vector<int> color(graph.size(), -1);
    for (int i = 0; i < graph.size(); i++)
    {
        for (auto it : graph[i])
        {
            adj[i].push_back(it);
        }
    }

    for (int i = 0; i < graph.size(); i++)
    {
        if (color[i] == -1)
        {
            q.push(i);
            color[i] = 1;
            while (!q.empty())
            {
                int front = q.front();
                q.pop();
                int front_color = color[front];
                for (auto it : adj[front])
                {
                    if (color[it] == -1)
                    {
                        color[it] = !(front_color);
                        q.push(it);
                    }
                    else if (color[it] == front_color)
                        return false;
                }
            }
        }
    }
    return true;
}

// Bipartile means dividing the graph by two colours.
// https://leetcode.com/problems/is-graph-bipartite/

int main()
{

    return 0;
}