#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
class Node
{
    public:
        Node* left;
        Node* right;
        int data;
        Node(int val)
        {
            data=val;
            left=NULL;
            right=NULL;
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
void travelLeft(Node* root,vector<int> &ans)
{
    if(root==NULL || (root->left==NULL and root->right==NULL))
        return;
    ans.push_back(root->data);
    if(root->left)
        travelLeft(root->left,ans);
    else
        travelLeft(root->right,ans);
}
void travelRight(Node* root,vector<int> &ans)
{
    if(root==NULL || (root->left==NULL and root->right==NULL))
        return;
    if(root->right)
        travelRight(root->right,ans);
    else
        travelRight(root->left,ans);
    ans.push_back(root->data);
}
void leafNode(Node* root,vector<int> &ans)
{
    if(root==NULL)
        return;
    if(root->left==NULL and root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }
    leafNode(root->left,ans);
    leafNode(root->right,ans);
}
vector<int> boundary(Node* root)
{
    vector<int> ans;
    ans.push_back(root->data);
    
    // left part boundary
    travelLeft(root->left,ans);

    // left subtree leaf node
    leafNode(root->left,ans);

    //right subtree leaf node
    leafNode(root->right,ans);

    //right part boundary
    travelRight(root->right,ans);
    
    return ans;
    
}
int main()
{
    Node* root=buildTree(root);
    vector<int> ans=boundary(root);
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/#
*/