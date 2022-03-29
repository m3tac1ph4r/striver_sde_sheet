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
    cout << "Enter Data : "
         << "\n";
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;

    cout << "Enter data for inserting left of " << data << "\n";
    root->left = buildTree(root->left);
    cout << "Enter data for inserting right of " << data << "\n";
    root->right = buildTree(root->right);
    return root;
}

vector<int> morrisInorderTraversal(Node* root)
{
    vector<int> inorder;
    Node* current=root;
    while(current!=NULL)
    {
        // checking whether current left is not present
        if(current->left==NULL)
        {
            inorder.push_back(current->data);
            current=current->right;
        }
        //current left part is present
        else
        {
            // finding the predecessor of current
            Node*  prev=current->left;
            while(prev->right !=NULL and prev->right!= current)
            {
                prev=prev->right;
            }
            // creating temporary link with predecessor of current 
            if(prev->right==NULL)
            {
                prev->right=current;
                current=current->left;
            }
            // removing the temporary link with predecessor of current
            else
            {
                prev->right=NULL;
                inorder.push_back(current->data);
                current=current->right;
            }
        }
    }
    return inorder;
}
int main()
{
    Node* root;
    root=buildTree(root);
    vector<int> ans=morrisInorderTraversal(root);
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}