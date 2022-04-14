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
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}
Node* solve(Node* root,int &k,int node)
{
    if(root==NULL)
        return NULL;
    if(root->data==node)
        return root;
    
    Node* leftAns=solve(root->left,k,node);
    Node* rightAns=solve(root->right,k,node);

    if(leftAns==NULL and rightAns!=NULL)
    {
        k--;
        if(k<=0)
        {
            k=INT_MAX;
            return root;
        }
        return rightAns;
    }
    if(leftAns!=NULL and rightAns==NULL)
    {
        k--;
        if(k<=0)
        {
            k=INT_MAX;
            return root;
        }
        return leftAns;
    }
    return NULL;
}
int kthAncesstor(Node* root,int k,int node)
{
    Node* ans=solve(root,k,node);
    if(ans==NULL || ans->data==node)
        return -1;
    else
    {
        return ans->data;
    }
}
int main()
{
    int k,node;
    cin>>node>>k;
    Node* root=buildTree(root);
    cout<<kthAncesstor(root,k,node);
    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1/#
*/