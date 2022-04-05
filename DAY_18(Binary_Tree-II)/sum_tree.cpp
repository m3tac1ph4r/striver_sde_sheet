#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int val)
    {
        data = val;
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
pair<int,bool> checkSum(Node* root)
{
    if(root==NULL)
    {
        pair<int,bool> p={0,true};
        return p;
    }
    else if (root->left ==NULL and root->right==NULL)
    {
        pair<int,bool> p={root->data,true};
        return p;
    }
    pair<int,bool> leftSubTree=checkSum(root->left);
    pair<int,bool> rightSubTree=checkSum(root->right);
    if(leftSubTree.second and rightSubTree.second and (leftSubTree.first+rightSubTree.first==root->data))
    {
        pair<int,bool> p={root->data+leftSubTree.first+rightSubTree.first,true};
        return p;
    }
    pair<int,bool> p;
    p.second=false;
    return p;
    }
bool isSumTree(Node* root)
{
    pair<int,bool> p;
    p=checkSum(root);
    return p.second;
}
int main()
{
    Node* root=buildTree(root);
    cout<<(isSumTree(root)==true?"True":"False");
    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/sum-tree/1#
*/