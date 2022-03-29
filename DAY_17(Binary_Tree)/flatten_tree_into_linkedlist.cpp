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
    cout << "Enter Data : "
         << "\n";
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;

    cout << "Enter data for inserting left of " << data << "\n";
    root->left = buildTree(root->left);
    cout << "Enter data for inserting right of " << data << "\n";
    root->right = buildTree(root->right);
    return root;
}
void flatten(Node *root)
{
    Node* current=root;
    while(current!=NULL)
    {
        if(current->left!=NULL)
        {
            Node* prev=current->left;
            while(prev!=NULL)
                prev=prev->right;
            prev->right=current->right;
            current->right=current->left;
            current->left=NULL;
        }
        current=current->right;
    }
}
int main()
{
    Node* root;
    root=buildTree(root);

    return 0;
}

/*
Solved this using Morris Preorder traversal because we do not have to use any extra auxillary space.

https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1/#
*/