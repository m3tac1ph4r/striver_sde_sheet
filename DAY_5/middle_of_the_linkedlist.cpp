#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

struct ListNode {
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
}

ListNode* middleNode(ListNode* head)
{
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main()
{
    ListNode* head=new ListNode();
    insertTail(head,1);
    insertTail(head,2);
    insertTail(head, 3);
    insertTail(head, 4);
    insertTail(head, 5);
    // display(head);
    ListNode* tmp=middleNode(head);
    display(tmp);
    return 0;
}

/*
Tortoise-Hare-Approach

In the Tortoise-Hare approach, we increment slow ptr by 1 and fast ptr by 2, so if take a close look fast ptr will travel double than that of the slow pointer. 
So when the fast ptr will be at the end of Linked List, slow ptr would have covered half of Linked List till then.
So slow ptr will be pointing towards the middle of Linked List.

https://leetcode.com/problems/middle-of-the-linked-list/
*/