#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    /*
    STEPS
    1. MAKE ADJACENCY LIST WITH REVERSE EDGES I.E V->U
    2. FIND OUTDEGREE FOR ALL VERTICES
    3. TO REVERSE TOPOSORT I.E USING OUTDEGREE
    */

    // STEP1. MAKE ADJACENCY LIST OF REVERSE EDGES
    int n = graph.size();
    vector<int> outDegree(n, 0);
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < n; i++)
    {
        // STEP 2. STORE OUTDEGREE OF ALL VERTICES
        outDegree[i] = graph[i].size();
        for (int j = 0; j < graph[i].size(); j++)
        {
            adj[graph[i][j]].push_back(i);
        }
    }

    // STEP 3. TOPOSORT
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (outDegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {
        int topNode = q.front();
        q.pop();
        ans.push_back(topNode);
        for (auto it : adj[topNode])
        {
            outDegree[it]--;
            if (outDegree[it] == 0)
                q.push(it);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}

//  USING REVERSE TOPOSORT
// https://leetcode.com/problems/find-eventual-safe-states/