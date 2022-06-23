#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

bool dfsCyclic(int node, vector<bool> &visited, vector<bool> &bag, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    bag[node] = true;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            bool ans = dfsCyclic(it, visited, bag, adj);
            if (ans == true)
                return true;
        }
        else if (bag[it])
            return true;
    }
    bag[node] = false;
    return false;
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    if (prerequisites.size() == 1 || numCourses == 0)
        return true;
    unordered_map<int, list<int>> adj;
    vector<bool> visited(numCourses, false);
    vector<bool> bag(numCourses, false);

    for (int i = 0; i < prerequisites.size(); i++)
    {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adj[v].push_back(u);
    }

    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
        {
            bool ans = dfsCyclic(i, visited, bag, adj);
            if (ans == true)
                return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/course-schedule/