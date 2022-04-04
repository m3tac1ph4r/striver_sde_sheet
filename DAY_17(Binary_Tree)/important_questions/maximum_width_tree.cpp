#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
class Node
{
    public:
        int data;
        Node* left;
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

int widthOfBinaryTree(Node* root) 
{
    int ans=0;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        int n=q.size();
        int start=q.front().second;
        int end=q.back().second;
        ans=max(ans,end-start+1);
        for(int i=0;i<n;i++)
        {
            pair<Node*,int> temp=q.front();
            q.pop();
            Node* node=temp.first;
            long idx=temp.second;
            if(node->left!=NULL)
                q.push({node->left,idx*2+1});
            if(node->right!=NULL)
                q.push({node->right,idx*2+2});
        }
    }
    return ans;
}    
int main()
{
    
    return 0;
}

/*
https://leetcode.com/problems/maximum-width-of-binary-tree/

See the notes in obsidian
*/