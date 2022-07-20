#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{
    vector<int> color(n + 1, -1);
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < dislikes.size(); i++)
    {
        int u = dislikes[i][0];
        int v = dislikes[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            q.push(i);
            color[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                int frontColor = color[node];
                for (auto it : adj[node])
                {
                    if (color[it] == -1)
                    {
                        color[it] = !frontColor;
                        q.push(it);
                    }
                    else if (color[it] == frontColor)
                        return false;
                }
            }
        }
    }
    return true;
}

int main()
{

    return 0;
}

// USING GRAPH COLORING BIPARTILE GRAPH
// https://leetcode.com/problems/possible-bipartition/