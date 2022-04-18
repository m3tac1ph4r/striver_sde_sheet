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

bool check(Node* node1,Node* node2)
{
    if(node1==NULL || node2==NULL)
        return node1==node2;
    
    return ((node1->data==node2->data) and check(node1->left,node2->right) and check(node1->right,node2->left));
}

bool isSymmetric(Node* root)
{
    return check(root->left,root->right);
}
int main()
{
    Node* root=buildTree(root);
    bool ans=isSymmetric(root);
    cout<<(ans==true?"True":"False");
    return 0;
}
/*
https://leetcode.com/problems/symmetric-tree/
*/