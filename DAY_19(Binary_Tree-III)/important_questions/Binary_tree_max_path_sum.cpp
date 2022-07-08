#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int solve(TreeNode *root, int &sum)
{
    if (root == NULL)
        return 0;

    int lh = max(0, solve(root->left, sum));
    int rh = max(0, solve(root->right, sum));

    sum = max(sum, root->val + lh + rh);

    return root->val + max(lh, rh);
}
int maxPathSum(TreeNode *root)
{
    int sum = INT_MIN;
    solve(root, sum);
    return sum;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/binary-tree-maximum-path-sum/