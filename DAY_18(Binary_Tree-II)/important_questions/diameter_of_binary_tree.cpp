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
int findMax(Node* root,int &maxi)
{
    if(root==NULL)
        return 0;
    int lh=findMax(root->left,maxi);
    int rh=findMax(root->right,maxi);
    maxi=max(maxi,rh+lh);
    return (1+max(lh,rh));
}
int diameterOfBinaryTree(Node* root)
{
    int diameter=0;
    findMax(root,diameter);
    return diameter;
}
int main()
{
    Node* root;
    root=buildTree(root);
    cout<<diameterOfBinaryTree(root);
    return 0;
}

/*
https://leetcode.com/problems/diameter-of-binary-tree/
*/