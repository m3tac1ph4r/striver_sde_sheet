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

vector<int> topView(Node* root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    map<int,int> topNode;   // int1 -> horizontal distance, int2 -> Node data
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<Node*,int> temp=q.front();
        q.pop();
        int hd=temp.second;
        if(topNode.find(hd)==topNode.end())
            topNode[hd]=temp.first->data;
        if(temp.first->left)
            q.push({temp.first->left,hd-1});
        if(temp.first->right)
            q.push({temp.first->right,hd+1});
    }
    for(auto i:topNode)
        ans.push_back(i.second);
    return ans;
}
int main()
{
    Node* root=buildTree(root);
    vector<int> ans=topView(root);
    for(auto i:ans)
        cout<<i<<" ";   
    return 0;
}

/*
Using level order traversal and map for 1:1 relation
https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1/#
*/