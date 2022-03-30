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
    // cout << "Enter Data : "<< "\n";
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;

    // cout << "Enter data for inserting left of " << data << "\n";
    root->left = buildTree(root->left);
    // cout << "Enter data for inserting right of " << data << "\n";
    root->right = buildTree(root->right);
    return root;
}
void search(Node* root,int B,vector<int> &ans)
{
    if(root==NULL)
        return;
    ans.push_back(root->data);
    search(root->left,B,ans);
    if(ans.back()==B)
        return;
    search(root->right,B,ans);
    if(ans.back()==B)
        return;
    ans.pop_back();
    return;
}
vector<int> solve(Node* root,int B)
{
    vector<int> ans;
    search(root,B,ans);
    return ans;
}
int main()
{   
    Node* root;
    root=buildTree(root);
    int B;
    cin>>B;
    vector<int> ans=solve(root,B);
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}
/*
https://www.interviewbit.com/problems/path-to-given-node/
*/

/*
Another Solution:

bool search(Node* root,int B,vector<int> &ans)
{
    if(root==NULL)
        return false;
    ans.push_back(root->data);
    if(root->data==B)
        return true;
    if(search(root->left,B,ans)||search(root->right,B,ans))
        return true;
    ans.pop_back();
    return false;
}
*/