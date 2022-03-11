#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode* bottom;
    ListNode(int data)
    {
        val = data;
        next = NULL;
        bottom=NULL;
    }
};
void insertTail(ListNode *&head, int val)
{
    ListNode *tmp = new ListNode(val);
    if (head == NULL)
        head = tmp;
    else
    {
        ListNode *n = head;
        while (n->next != NULL)
        {
            n = n->next;
        }
        n->next = tmp;
    }
}
void display(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}
ListNode *mergeList(ListNode *a, ListNode *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    ListNode *temp = new ListNode(0);
    ListNode *res = temp;
    while (a != NULL and b != NULL)
    {
        if (a->val < b->val)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if (a != NULL)
    {
        temp->bottom = a;
    }
    else
        temp->bottom = b;
    return res->bottom;
}
ListNode *flatten(ListNode *root)
{
    // Your code here
    if (root == NULL or root->next == NULL)
        return root;

    root->next = flatten(root->next);
    root = mergeList(root, root->next);
    return root;
}
int main()
{
    ListNode* head=NULL;
    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#

For more detail solution:
https://www.youtube.com/watch?v=ysytSSXpAI0&ab_channel=takeUforward
*/