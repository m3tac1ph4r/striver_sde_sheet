#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

Node* buildTree(Node* root)
{
    int data;
    cout<<"Enter Data : "<<"\n";
    cin>>data;
    root=new Node(data);
    if(data==-1)
        return NULL;
    
    cout<<"Enter data for inserting left of "<<data<<"\n";
    root->left=buildTree(root->left);
    cout << "Enter data for inserting right of " << data << "\n";
    root->right=buildTree(root->right);
    return root;
}

void levelOrderTraversal(Node* root)
{
    // LEVEL ORDER TRAVERSAL IS ALSO KNOWN AS DEPTH FIRST SEARCH
    /* for levelOrderTraversal we used a delimenter called NULL
    We will push NULL when the level ends
    like after level 0 (root) we pushed NULL same we will do if we q->front() is NULL and q 
    is having some  elements.
    */
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if(temp==NULL)      // means we got the delimeter NULL
        {
            cout<<"\n";
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
    }
    }
}

void reverseOrderTraversal(Node *root)
{
    queue<Node *> q;
    stack<Node *> myStack;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        myStack.push(temp);
        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
    }
    while(!myStack.empty())
    {
        Node* temp=myStack.top();
        cout<<temp->data<<" ";
        myStack.pop();
    }
}

void inorderTraversal(Node* root)
{
    if(root==NULL)
        return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root)
{
    if(root==NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}
int main()
{
    Node* root;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //1 2 4 -1 -1 5 -1 6 -1 -1 3 -1 -1
    root=buildTree(root);
    cout<<"Printing levelOrderTraversal "<<endl;
    levelOrderTraversal(root);
    reverseOrderTraversal(root);
    cout << "Printing reverseOrderTraversal " << endl;
    inorderTraversal(root);
    cout<<"Printing Inoder traversal"<<"\n";
    preorderTraversal(root);
    cout<<"Printing Preorder traversal"<<"\n";
    postorderTraversal(root);
    cout<<"Printing Postorder traversal"<<"\n";
    return 0;
}
