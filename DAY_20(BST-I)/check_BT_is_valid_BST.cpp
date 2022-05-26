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

class Solution
{
public:
    bool solve(TreeNode *root, long low, long high)
    {
        if (root == NULL)
            return true;
        if (root->val <= low || root->val >= high)
            return false;

        return (solve(root->left, low, root->val) and solve(root->right, root->val, high));
    }
    bool isValidBST(TreeNode *root)
    {
        long low = LONG_MIN;
        long high = LONG_MAX;
        return solve(root, low, high);
    }
};

// https://leetcode.com/problems/validate-binary-search-tree/