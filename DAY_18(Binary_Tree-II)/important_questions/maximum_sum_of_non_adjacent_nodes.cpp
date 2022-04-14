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

pair<int,int> solve(Node* root)
{
    // base case
    if(root==NULL)
        return {0,0};
    
    pair<int,int> leftSum=solve(root->left);
    pair<int,int> rightSum=solve(root->right);

    pair<int,int> res;
    res.first=root->data+leftSum.second+rightSum.second;    // including root and excluding child of root
    res.second=max(leftSum.first,leftSum.second)+max(rightSum.first,rightSum.second);
    // excluding root and including there child
    return res;
}
int getMaxSum(Node* root)
{
    /*
    // pair<int a,int b>
    // a means including that node at that level now its parent and child cannnot be included
    // b means excluding that node at that level 
    */
    pair<int,int> ans=solve(root);
    return max(ans.first,ans.second);
}
int main()
{
    Node* root=buildTree(root);
    cout<<getMaxSum(root);
    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1/#
*/