#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> distance(n + 1, 1e9);
    distance[src] = 0;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (distance[u] == 1e9)
                continue;
            else if (distance[u] + w < distance[v])
                distance[v] = distance[u] + w;
        }
    }
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (distance[u] == 1e9)
            continue;
        else if (distance[u] + w < distance[v])
            return 1e9;
    }
    return distance[dest];
}

int main()
{

    return 0;
}

// https://www.codingninjas.com/codestudio/problems/2041977
// https://youtu.be/ijpVpsmpJtQ?list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA

/*
1. Create a distance array of size N with default value 1e9. Mark distance[src]=0
2. Then ignore all the nodes before source. Then update the distance of node[v] in u->v edges.
3. Do STEP 2 n-1 times. Because suppose we have n vertices and eacah iteration only one edge is update then we
need total n-1 iteration to get shortest path from source.
*/