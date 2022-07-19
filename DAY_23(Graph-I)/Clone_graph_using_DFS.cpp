#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *dfs(Node *curr, unordered_map<Node *, Node *> &mp)
{
    vector<Node *> neighbour;
    Node *clone = new Node(curr->val);
    mp[curr] = clone;

    for (auto it : curr->neighbors)
    {
        if (mp.find(it) != mp.end())
            neighbour.push_back(mp[it]);
        else
        {
            neighbour.push_back(dfs(it, mp));
        }
    }
    clone->neighbors = neighbour;
    return clone;
}
Node *cloneGraph(Node *node)
{
    if (node == NULL)
        return NULL;
    else if (node->neighbors.size() == 0)
    {
        Node *clone = new Node(node->val);
        return clone;
    }

    unordered_map<Node *, Node *> mp;
    return dfs(node, mp);
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/clone-graph/
/*
We will use map for storing
ORIGINAL_NODE    CLONE_NODE
1                   1
2                   2
3                   3

*/