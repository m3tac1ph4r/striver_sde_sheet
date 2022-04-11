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

void findPathSum(Node* root,int sum,int len,int &maxSum,int &maxLen)
{
    if(root==NULL)
    {
        if(len>maxLen)
        {
            maxLen=len;
            maxSum=sum;
        }
        else if(len==maxLen)
            maxSum=max(sum,maxSum);
        return;
    }

    sum+=root->data;
    findPathSum(root->left,sum,len+1,maxSum,maxLen);        //left node call
    findPathSum(root->right, sum, len + 1, maxSum, maxLen); //right node call
}

int sumOfLongRootToLeafNode(Node* root)
{
    int maxSum=INT_MIN,maxLen=0;
    findPathSum(root,0,0,maxSum,maxLen);
    return maxSum;
}
int main()
{
    Node* root=buildTree(root);
    cout<<sumOfLongRootToLeafNode(root);
    return 0;
}