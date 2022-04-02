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
int check_balanced(Node* root)
{
    if(root==NULL)
        return 0;
    int lh=check_balanced(root->left);
    if(lh==-1)
        return -1;
    int rh=check_balanced(root->right);
    if(rh==-1)
        return -1;
    if(abs(lh-rh)>1)
        return -1;
    return (1+max(lh,rh));
}
bool isBalanced(Node* root)
{
    if(check_balanced(root)!=-1)
        return true;
    else
        return false;
}
int main()
{
    Node* root;
    root=buildTree(root);
    cout<<(isBalanced(root)==true?"True":"False");
    return 0;
}

/*
Solved Using PostOrder

https://leetcode.com/problems/balanced-binary-tree/
*/