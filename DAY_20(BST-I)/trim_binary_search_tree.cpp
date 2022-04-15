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
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL) // means we got the delimeter NULL
        {
            cout << "\n";
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
Node *trimBST(Node *root, int low, int high)
{
    // base case
    if (root == NULL)
        return NULL;

    if (root->data >= low and root->data <= high)
    {
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
    else if (root->data < low)
        return trimBST(root->right, low, high);
    else if (root->data > high)
        return trimBST(root->left, low, high);

    return root;
}
int main()
{
    int low,high;
    cin >> low>>high;
    Node *root = buildTree(root);
    root = trimBST(root, low, high);
    levelOrderTraversal(root);
    return 0;
}

/*
https://leetcode.com/problems/trim-a-binary-search-tree/
*/