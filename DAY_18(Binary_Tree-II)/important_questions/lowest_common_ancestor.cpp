#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

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
    // cout << "Enter Data : "<< "\n";
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;

    // cout << "Enter data for inserting left of " << data << "\n";
    root->left = buildTree(root->left);
    // cout << "Enter data for inserting right of " << data << "\n";
    root->right = buildTree(root->right);
    return root;
}
Node* lowestCommonAncestor(Node* root,Node* p,Node* q)
{
    if (root == NULL || root == p || root == q)
        return root;
    Node *temp_left = lowestCommonAncestor(root->left, p, q);
    Node *temp_right = lowestCommonAncestor(root->right, p, q);
    if (temp_left == NULL)
        return temp_right;
    else if (temp_right == NULL)
        return temp_left;
    else
        return root;
}
int main()
{
    
    return 0;
}

/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/