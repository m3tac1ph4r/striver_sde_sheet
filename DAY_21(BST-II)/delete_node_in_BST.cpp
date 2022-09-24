#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int x)
    {
        left = NULL;
        right = NULL;
        data = x;
    }
};
Node *findRight(Node *root)
{
    if (root->right == NULL)
        return root;

    return findRight(root->right);
}
Node *helper(Node *root)
{
    if (root->left == NULL)
        return root->right;
    else if (root->right == NULL)
        return root->left;
    Node *rightChild = root->right;
    Node *extremeRt = findRight(root->left);
    extremeRt->right = rightChild;
    return root->left;
}
// Function to delete a node from BST.
Node *deleteNode(Node *root, int X)
{
    // your code goes here
    Node *dummy = root;
    if (root->data == X)
        return helper(root);
    while (root != NULL)
    {
        if (root->data > X)
        {
            if (root->left != NULL and root->left->data == X)
            {
                root->left = helper(root->left);
                break;
            }
            else
                root = root->left;
        }
        else
        {
            if (root->right != NULL and root->right->data == X)
            {
                root->right = helper(root->right);
                break;
            }
            else
                root = root->right;
        }
    }
    return dummy;
}
int main()
{

    return 0;
}