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

int maxDepth(Node* root)
{
    if(root==NULL)
        return 0;
    queue<Node*> q;
    int count=0;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            count++;
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return count;
}
int main()
{
    Node* root;
    root=buildTree(root);
    cout<<maxDepth(root);
    return 0;
}

/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/