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
vector<vector<int>> zigzagLevelOrder(Node* root)
{
    vector<vector<int>> ans;
    if(root==NULL)
        return ans;
    queue<Node*> q;
    bool leftToRight=true;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int> arr(size);
        for(int i=0;i<size;i++)
        {
            Node* frontNode=q.front();
            q.pop();
            int index=(leftToRight==true)?i:size-i-1;
            arr[index]=frontNode->data;
            if(frontNode->left)
                q.push(frontNode->left);
            if(frontNode->right)
                q.push(frontNode->right);
        }
        ans.push_back(arr);
        leftToRight=!leftToRight;
    }
    return ans;
}
int main()
{
    Node* root=buildTree(root);
    vector<vector<int>> ans=zigzagLevelOrder(root);
    for(auto i:ans)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<"\n";
    }
    return 0;
}
/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
*/