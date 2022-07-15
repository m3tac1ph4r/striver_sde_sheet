#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

void topoSort(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, stack<int> &st)
{
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (!visited[it])
            topoSort(it, adj, visited, st);
    }
    st.push(node);
}
void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &transpose)
{
    visited[node] = true;
    for (auto it : transpose[node])
    {
        if (!visited[it])
        {
            dfs(it, visited, transpose);
        }
    }
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // base case if there is no edge means only one component
    if (v == 1)
        return 1;

    // create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // 1. find topologicalSort
    stack<int> st;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            topoSort(i, adj, visited, st);
    }

    // 2. find transpose of graph i.e reverse all the edges of graph {v->u}
    int count = 0;
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        for (auto it : adj[i])
            transpose[it].push_back(i);
    }

    // 3. dfs of transpose graph
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!visited[top])
        {
            count++;
            dfs(top, visited, transpose);
        }
    }
    return count;
}

int main()
{

    return 0;
}

/*
1. Find topological sort of graph
2. Transpose the graph
3. Do DFS of transpose graph using topoSort Stack
*/

// https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151
// https://www.codingninjas.com/codestudio/problems/985311
// https://youtu.be/ndfjV_yHpgQ