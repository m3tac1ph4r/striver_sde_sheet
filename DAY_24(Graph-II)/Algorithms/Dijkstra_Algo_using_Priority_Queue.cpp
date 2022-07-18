#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> adj; // in pair first int will be for vertex and second is for weight

    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];

        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
    }

    vector<int> distance(vertices, INT_MAX);

    distance[source] = 0;
    // min heap priority queue
    // 	priority_queue<type, vector<type>, greater<type>> pq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int nodeDist = top.first;
        int node = top.second;

        for (auto neighbour : adj[node])
        {
            if (nodeDist + neighbour.second < distance[neighbour.first])
            {
                distance[neighbour.first] = nodeDist + neighbour.second;

                pq.push({distance[neighbour.first], neighbour.first});
            }
        }
    }
    return distance;
}
int main()
{

    return 0;
}

// Shortest Path in undirected weighted graph
// https://youtu.be/dVUR3Rm6biE?list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA
// https://www.codingninjas.com/codestudio/problems/920469