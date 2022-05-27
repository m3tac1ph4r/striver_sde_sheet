#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

struct Node
{
    int key;
    struct Node *left, *right;
};

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    pre = NULL;
    suc = NULL;

    Node *temp = root;
    // successor
    while (temp != NULL)
    {
        if (temp->key > key)
        {
            suc = temp;
            temp = temp->left;
        }
        else
            temp = temp->right;
    }
    // predecessor
    temp = root;
    while (temp != NULL)
    {
        if (temp->key < key)
        {
            pre = temp;
            temp = temp->right;
        }
        else
            temp = temp->left;
    }
}
int main()
{
    
    return 0;
}

//  SUCCESSOR OF X MEANS NODE WHICH IS JUST GREATER THAN X.
//  PREDECESSOR OF X MEANS NODE WHICH IS JUST SMALLER THAN X.

// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1#
// https: // www.youtube.com/watch?v=SXKAD2svfmI&ab_channel=takeUforward