#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class info
{
public:
    int maxi;
    int mini;
    bool isvalidBST;
    int size;
};

info solve(Node *root, int &ans)
{
    if (root == NULL)
        return {INT_MIN, INT_MAX, true, 0};

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info curr;
    curr.maxi = max(root->data, right.maxi);
    curr.mini = min(root->data, left.mini);

    curr.size = left.size + right.size + 1;

    if (left.isvalidBST and right.isvalidBST and (left.maxi < root->data and root->data < right.mini))
    {
        ans = max(curr.size, ans); // answer update
        curr.isvalidBST = true;
    }
    else
        curr.isvalidBST = false;
    return curr;
}
int largestBST(Node *root)
{
    // Write your code here.
    int ans = 0;
    solve(root, ans);
    return ans;
}

int main()
{
    
    return 0;
}

//  https://www.codingninjas.com/codestudio/problems/largest-bst-subtree_893103
// https://youtu.be/fqx8z3VepMA?list=PLDzeHZWIZsTpTAcxT0N5dhzMauZ0A1ZL8