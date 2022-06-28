#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> ans;
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto it : adj[front])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return ans;
}
int main()
{

    return 0;
}

// https://practice.geeksforgeeks.org/problems/topological-sort/1#