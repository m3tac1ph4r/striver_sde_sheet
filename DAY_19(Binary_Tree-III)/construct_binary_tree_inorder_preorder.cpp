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

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL) // means we got the delimeter NULL
        {
            cout << "\n";
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void createMapping(vector<int> inorder,map<int,int> &nodeToIndex,int n)
{
    for(int i=0;i<n;i++)
        nodeToIndex[inorder[i]]=i;
}

Node* solve(vector<int> inorder,vector<int> preorder,int n,int &index,map<int,int> &nodeToIndex,int inorderStart,int inorderEnd)
{
    // base case
    if(index>=n || inorderStart>inorderEnd)
        return NULL;
    
    int element=preorder[index++];
    Node* root=new Node(element);
    int position=nodeToIndex[element];
    
    //recursive call
    root->left=solve(inorder,preorder,n,index,nodeToIndex,inorderStart,position-1);
    root->right=solve(inorder,preorder,n,index,nodeToIndex,position+1,inorderEnd);

    return root;
}

Node* buildTree(vector<int> inorder,vector<int> preorder)
{
    int n=inorder.size();
    map<int,int> nodeToIndex;
    createMapping(inorder,nodeToIndex,n);
    int index=0,inorderStart=0,inorderEnd=n-1;
    Node* ans=solve(inorder,preorder,n,index,nodeToIndex,inorderStart,inorderEnd);
    return ans;
}
int main()
{
    vector<int> preorder={1,6,7,8};
    vector<int> inorder={1,6,8,7};
    Node* root=buildTree(inorder,preorder);
    levelOrderTraversal(root);
    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/construct-tree-1/1/#
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


https://www.youtube.com/watch?v=ffE1xj51EBQ&list=PLDzeHZWIZsTo87y1ytEAqp7wYlEP3nner&index=6&ab_channel=CodeHelp-byBabbar
*/