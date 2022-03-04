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

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next_p;
    while (curr != NULL)
    {
        next_p = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_p;
    }
    head = prev;
    return head;
}
void reorderList(ListNode*  head)
{
    ListNode* slow=head;
    ListNode* fast=head->next;
    while (fast!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* second=reverseList(slow->next);
    slow->next=NULL;
    ListNode* first=head;
    while(second!=NULL)
    {
        ListNode* temp1=first->next;
        ListNode* temp2=second->next;
        first->next=second;
        second->next=temp1;
        first=temp1;
        second=temp2;
    }
}
int main()
{
    
    return 0;
}

/*
https://leetcode.com/problems/reorder-list/

Firstly find middle of the linked list 
Then divide the linkedlist in two halves first and second. 
For Example: 1->2->3->4->5
First: 1->2->3
Second: 4->5

Now reversed the second part
Second: 5->4

Now merge first and second

1->5->2->4->3

*/