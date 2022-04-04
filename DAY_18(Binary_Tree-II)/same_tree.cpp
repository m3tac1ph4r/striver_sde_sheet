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
bool isSameTree(Node* p,Node* q)
{
    if(p==NULL || q==NULL)
        return (p==q);
    return ((p->data==q->data) and isSameTree(p->left,q->left) and isSameTree(p->right,q->right));
}
int main()
{
    Node* p;
    Node* q;
    p=buildTree(p);
    q=buildTree(q);
    cout<<(isSameTree(p,q)==true?"True":"False");
    return 0;
}

/*
https://leetcode.com/problems/same-tree/
*/