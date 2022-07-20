#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        visited[node] = true;
        for (int it : rooms[node])
        {
            if (visited[it] == false)
                q.push(it);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
            return false;
    }
    return true;
}

int main()
{

    return 0;
}

// USING BFS
// https://leetcode.com/problems/keys-and-rooms/