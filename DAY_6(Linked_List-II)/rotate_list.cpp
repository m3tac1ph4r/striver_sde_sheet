#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int data)
    {
        val = data;
        next = NULL;
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
ListNode* rotateRight(ListNode* head,int k)
{
    ListNode* curr=head;
    int count=1;
    while(curr->next!=NULL)
    {
        count++;
        curr=curr->next;
    }
    curr->next=head;
    k=k%count;
    k=count-k;
    while(k>0)
    {
        curr=curr->next;
        k--;
    }
    head=curr->next;
    curr->next=NULL;
    return head;
}
int main()
{
    ListNode* head=NULL;
    insertTail(head,1);
    insertTail(head,2);
    insertTail(head, 3);
    insertTail(head, 4);
    insertTail(head, 5);
    display(head);
    ListNode* temp=rotateRight(head,2);
    display(temp);
    return 0;
}

/*
https://leetcode.com/problems/rotate-list/description/
*/
