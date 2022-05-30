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
class Solution
{
public:
    Node *createMapping(Node *root, int target, map<Node *, Node *> &childToParent)
    {
        Node *res;
        queue<Node *> q;
        q.push(root);
        childToParent[root] == NULL;
        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();

            if (front->data == target)
                res = front;

            if (front->left)
            {
                childToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right)
            {
                childToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }

    int solve(Node *target, map<Node *, Node *> &childToParent)
    {
        map<Node *, bool> visited;
        queue<Node *> q;
        q.push(target);
        visited[target] = true;
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++)
            {
                Node *front = q.front();
                q.pop();

                if (front->left and !visited[front->left])
                {
                    flag = true;
                    visited[front->left] = true;
                    q.push(front->left);
                }
                if (front->right and !visited[front->right])
                {
                    flag = true;
                    visited[front->right] = true;
                    q.push(front->right);
                }
                if (childToParent[front] and !visited[childToParent[front]])
                {
                    flag = true;
                    visited[childToParent[front]] = true;
                    q.push(childToParent[front]);
                }
            }
            if (flag)
                ans++;
        }
        return ans;
    }
    int minTime(Node *root, int target)
    {
        // 1. Map child nodes with their parent
        // 2. Return target Node
        // 3. Map visited node and find the minimum time required to burn the tree
        map<Node *, Node *> childToParent;
        Node *tar = createMapping(root, target, childToParent);

        int ans = solve(tar, childToParent);

        return ans;
    }
};

// https://practice.geeksforgeeks.org/problems/burning-tree/1#
// https://youtu.be/XLdpy0_6MR4?list=PLDzeHZWIZsTo87y1ytEAqp7wYlEP3nner