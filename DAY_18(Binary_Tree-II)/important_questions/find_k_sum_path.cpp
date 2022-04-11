#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

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

Node *buildTree(Node *root)
{
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}
void findCount(Node *root, int k, int &count, vector<int> ans)
{
    if (root == NULL)
        return;
    ans.push_back(root->data);
    findCount(root->left, k, count, ans);
    findCount(root->right, k, count, ans);
    int sum = 0;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        sum += ans[i];
        if (sum == k)
        {
            count++;
        }
    }
    ans.pop_back();
}
int sumK(Node *root, int k)
{
    // code here
    int count = 0;
    vector<int> ans;
    findCount(root, k, count, ans);
    return count;
}
int main()
{
    int k;
    cin>>k;
    Node* root=buildTree(root);
    cout<<sumK(root,k);
    return 0;
}