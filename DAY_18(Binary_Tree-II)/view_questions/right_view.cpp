#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

vector<int> rightView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> hash_map;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> tempNode = q.front();
        q.pop();
        int level = tempNode.second;
        hash_map[level] = tempNode.first->data;
        if (tempNode.first->left)
            q.push({tempNode.first->left, level + 1});
        if (tempNode.first->right)
            q.push({tempNode.first->right, level + 1});
    }
    for (auto i : hash_map)
    {
        ans.push_back(i.second);
    }
    return ans;
}
int main()
{
    Node *root = buildTree(root);
    vector<int> ans = rightView(root);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}

/*
Using level order traversal
https://leetcode.com/problems/binary-tree-right-side-view/
*/