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

class Solution
{
public:
    void inorderTraversal(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
            return;
        inorderTraversal(root->left, arr);
        arr.push_back(root->val);
        inorderTraversal(root->right, arr);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> arr;
        inorderTraversal(root, arr);
        return arr[k - 1];
    }
};

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/