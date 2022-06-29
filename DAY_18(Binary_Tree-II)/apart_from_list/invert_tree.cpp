#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
        return NULL;

    TreeNode *new_node = new TreeNode(root->val);
    new_node->left = invertTree(root->right);
    new_node->right = invertTree(root->left);

    return new_node;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/invert-binary-tree/