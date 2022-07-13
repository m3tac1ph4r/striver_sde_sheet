#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

bool comp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
int findParent(int node, vector<int> &parent)
{
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node], parent); // path compression
    // we will update the parent. Suppose parent of 6 is 4 and parent of 4 is 1. This will make parent[6]=1
}
void unionSet(int u, int v, vector<int> &rank, vector<int> &parent)
{
    if (rank[u] < rank[v])
    {
        parent[u] = v;
        rank[v]++;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
        rank[u]++;
    }
    else // if rank[u]==rank[v]
    {
        parent[u] = v;
        rank[v]++;
    }
}
int kruskalMST(int n, int m, vector<vector<int>> &graph)
{
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 0; i <= n; i++)
        parent[i] = i;
    int min_wt = 0;
    sort(graph.begin(), graph.end(), comp); // sort the graph acc to weight
    for (int i = 0; i < m; i++)
    {
        int u = findParent(graph[i][0], parent);
        int v = findParent(graph[i][1], parent);
        int wt = graph[i][2];
        if (u != v)
        {
            min_wt += wt;
            unionSet(u, v, rank, parent);
        }
    }
    return min_wt;
}
int main()
{

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/1082553
// https://youtu.be/KxLtIrCyXwE?list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA