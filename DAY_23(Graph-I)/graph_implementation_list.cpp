#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        // direction 0 -> undirected
        // direction 1 -> directed

        // create an edge from u to v

        adj[u].push_back(v);

        if (direction == 0)
            adj[v].push_back(u);
    }

    void printEdge()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};
int main()
{
    int n, m;
    cout << "Enter the number of edges"
         << "\n";
    cin >> n;

    cout << "Enter the number of vertices"
         << "\n";
    cin >> m;

    Graph<int> g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.printEdge();
    return 0;
}

// USING ARRAY OF VECTORS
// adj[5] means there will be 5 vectors in adj
/*
    int main() {
    int n, m;
    cin >> n >> m;

    // declare the adjacent matrix
    vector<int> adj[n+1];

    // take edges as input
    for(int i = 0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}
*/