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
ListNode* middle(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
bool isPalindrome(ListNode* head)
{
    ListNode* mid=middle(head);
    ListNode* curr=mid;
    ListNode* prev=NULL;
    ListNode* nexxt;
    while(curr!=NULL)
    {
        nexxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nexxt;
    }
    while (prev!=NULL)
    {
        if(head->val!=prev->val)
            return false;
        head=head->next;
        prev=prev->next;
    }
    return true;
}

int main()
{
    ListNode* head=NULL;
    insertTail(head,1);
    insertTail(head, 2);
    insertTail(head, 2);
    insertTail(head, 1);
    display(head);
    cout<<isPalindrome(head);
    return 0;
}

/*
https://leetcode.com/problems/palindrome-linked-list/

Approach:
1. Firstly Find mid node
2. Then reverse the list after mid
3. Then check the value of head linked_list and reverse_head(prev) linked_list
    ex: 10203
    mid: 2
    Now modifies list will be: 10302
    Now we will we will travese from 1 to 3 and 3 to 2.
    And check whether values are same or not.
*/