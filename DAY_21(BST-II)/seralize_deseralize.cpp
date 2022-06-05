#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s = "";
        queue<TreeNode *> q;
        if (root == NULL)
            return "";
        q.push(root);
        // s=to_string(root->val);

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL)
                // s=s+'#'+",";
                s.append("#,");
            else
                // s=s+to_string(temp->val)+',';
                s.append(to_string(temp->val) + ',');
            if (temp != NULL)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.length() == 0)
            return NULL;

        stringstream ss(data);
        string str;

        getline(ss, str, ',');
        TreeNode *root = new TreeNode(stoi(str));

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            // LEFT SUBTREE
            getline(ss, str, ',');

            if (str == "#")
                temp->left = NULL;
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                temp->left = leftNode;
                q.push(leftNode);
            }

            // RIGHT SUBTREE

            getline(ss, str, ',');

            if (str == "#")
                temp->right = NULL;
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                temp->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/