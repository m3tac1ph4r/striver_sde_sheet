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
void solve(TreeNode *root, vector<string> &ans, string merge)
{
    if (root == NULL)
        return;
    else if (root->left == NULL and root->right == NULL)
    {
        merge = merge + to_string(root->val);
        ans.push_back(merge);
        return;
    }
    string temp = to_string(root->val);
    merge = merge + temp + "->";
    solve(root->left, ans, merge);
    solve(root->right, ans, merge);
}
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;
    string merge = "";
    solve(root, ans, merge);
    return ans;
}
int main()
{

    return 0;
}

// https://leetcode.com/problems/binary-tree-paths/