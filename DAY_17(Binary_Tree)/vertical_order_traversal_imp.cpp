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
vector<vector<int>> verticalTraversal(Node* root)
{
    vector<vector<int>> ans;
    queue<pair<Node*,pair<int,int>>> q;     // queue -> (node,vertical,level)
    map<int,map<int,multiset<int>>> m;      // map -> (vertical,{level,multinode})
    q.push({root,{0,0}});
    while(!q.empty())
    {
        auto temp=q.front();
        q.pop();
        int vertical=temp.second.first;
        int level=temp.second.second;
        Node* node=temp.first;
        m[vertical][level].insert(node->data);

        if(node->left)
            q.push({node->left,{vertical-1,level+1}});
        if(node->right)
            q.push({node->right,{vertical+1,level+1}});
    }

    for (auto p : m)        // for first map i.e map<int,map<int,multiset<int>>> m;
    {
        vector<int> col;
        for (auto q : p.second)     // for second map i.e map<int,multiset<int>>
        {
            for (auto i : q.second) // for multiset in second map i.e multiset<int>
                col.push_back(i);

            // col.insert(col.end(),q.second.begin(),q.second.end());  //this is the alternative for above for loop
        }
        ans.push_back(col);
    }
    return ans;
}
int main()
{
    Node* root;
    root=buildTree(root);
    vector<vector<int>> ans=verticalTraversal(root);
    for(auto i:ans)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}

// MOST IMPORTANT QUESTION
/*
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
*/
/*
If simple vertical level order is asked

    void solve(TreeNode* root,int hdistance,map<int,vector<int>> &m)
    {
        if(root==NULL)
            return;

        m[hdistance].push_back(root->val);

        solve(root->left,hdistance-1,m);
        solve(root->right,hdistance+1,m);
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<int>> m;
        int hdistance=0;
        solve(root,hdistance,m);
        map<int,vector<int>>::iterator it;
        for(it=m.begin();it!=m.end();it++)
        {
            vector<int> temp;
            for(int i=0;i<(it->second).size();i++)
            {
                temp.push_back((it->second)[i]);
            }
            ans.push_back(temp);
}
        return ans;
    }
*/