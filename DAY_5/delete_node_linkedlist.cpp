#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

void deleteNode(ListNode* &node)
{
    ListNode *p = node->next;
    node->val = p->val;
    node->next = p->next;
    delete p;
}
int main()
{
    ListNode* head=new ListNode();
    insertTail(head,4);
    insertTail(head, 5);
    insertTail(head, 6);
    insertTail(head, 1);
    insertTail(head, 9);
    int n;
    cin>>n;
    ListNode* p=head;
    while (n--)
    {
        p=p->next;
    }
    deleteNode(p);
    display(head->next);
    return 0;
}

/*
https://leetcode.com/problems/delete-node-in-a-linked-list/
*/