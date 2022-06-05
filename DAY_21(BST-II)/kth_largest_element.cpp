#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

void solve(Node *root, vector<int> &arr)
{
    if (root == NULL)
        return;
    solve(root->right, arr);
    arr.push_back(root->data);
    solve(root->left, arr);
}
int kthLargest(Node *root, int K)
{
    // Your code here
    vector<int> arr;
    solve(root, arr);
    return arr[K - 1];
}

// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
