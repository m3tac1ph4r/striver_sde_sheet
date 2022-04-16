#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

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

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL) // means we got the delimeter NULL
        {
            cout << "\n";
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void createMapping(vector<int> inorder, map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
        nodeToIndex[inorder[i]] = i;
}

Node *solve(vector<int> inorder, vector<int> postorder, int n, int &index, map<int, int> &nodeToIndex, int inorderStart, int inorderEnd)
{
    // base case
    if (index<0 || inorderStart > inorderEnd)
        return NULL;

    int element = postorder[index--];
    Node *root = new Node(element);
    int position = nodeToIndex[element];

    // recursive call
    // we have recursive call for right first because index started from end
    root->right = solve(inorder, postorder, n, index, nodeToIndex, position + 1, inorderEnd);
    root->left = solve(inorder, postorder, n, index, nodeToIndex, inorderStart, position - 1);

    return root;
}

Node *buildTree(vector<int> inorder, vector<int> postorder)
{
    int n = inorder.size();
    map<int, int> nodeToIndex;
    createMapping(inorder, nodeToIndex, n);
    int index = n-1, inorderStart = 0, inorderEnd = n - 1;
    Node *ans = solve(inorder, postorder, n, index, nodeToIndex, inorderStart, inorderEnd);
    return ans;
}
int main()
{
    vector<int> postorder = {8,4,5,2,6,7,3,1};
    vector<int> inorder = {4,8,2,5,1,6,3,7};
    Node *root = buildTree(inorder, postorder);
    levelOrderTraversal(root);
    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1/#
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


https://www.youtube.com/watch?v=ffE1xj51EBQ&list=PLDzeHZWIZsTo87y1ytEAqp7wYlEP3nner&index=6&ab_channel=CodeHelp-byBabbar
*/