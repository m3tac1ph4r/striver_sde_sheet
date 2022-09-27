#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;
class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
Node *findLCA(Node *root, int a, int b)
{
    if (root == NULL || root->data == a || root->data == b)
        return root;

    Node *left = findLCA(root->left, a, b);
    Node *right = findLCA(root->right, a, b);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root;
}
int distLCA(Node *lca, int num, int count)
{
    if (lca == NULL)
        return -1;
    if (lca->data == num)
        return count;

    int leftDist = distLCA(lca->left, num, count + 1);
    if (leftDist != -1)
        return leftDist;
    int rightDist = distLCA(lca->right, num, count + 1);
    return rightDist;
}
int findDist(Node *root, int a, int b)
{
    // Your code here
    Node *lca = findLCA(root, a, b);
    int aToLCA = distLCA(lca, a, 0);
    int bToLCA = distLCA(lca, b, 0);
    return aToLCA + bToLCA;
}

int main()
{

    return 0;
}

// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/