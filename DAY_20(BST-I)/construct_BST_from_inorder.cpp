#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    map<int,int> createMapping(vector<int> &inorder)
    {
        map<int,int> nodeToIndex;
        for(int i=0;i<inorder.size();i++)
            nodeToIndex[inorder[i]]=i;
        return nodeToIndex;
}
    TreeNode* solve(vector<int> &inorder,vector<int> &preorder,int n,int &index,map<int,int> nodeToIndex,int inorderStart,int inorderEnd)
    {
        if(index>=n || inorderStart>inorderEnd)
            return NULL;
        
        int element=preorder[index++];
        int position=nodeToIndex[element];
        
        TreeNode* root=new TreeNode(element);
        
        root->left=solve(inorder,preorder,n,index,nodeToIndex,inorderStart,position-1);
        root->right=solve(inorder,preorder,n,index,nodeToIndex,position+1,inorderEnd);
        
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        int index=0,inorderStart=0,n=inorder.size(),inorderEnd=n-1;
        map<int,int> nodeToIndex=createMapping(inorder);
        return solve(inorder,preorder,n,index,nodeToIndex,inorderStart,inorderEnd);
    }
};

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

// INORDER OF BST IS ALWAYS SORTED.