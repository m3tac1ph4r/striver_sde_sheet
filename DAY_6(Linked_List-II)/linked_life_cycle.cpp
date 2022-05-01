#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
class ListNode
{
    public:
    int val;
    ListNode* next;
    ListNode(int data)
    {
        val=data;
        next=NULL;
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
bool hasCycle(ListNode* head)
{
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast!=NULL and fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
            return true;
    }
    return false;
}
int main()
{
    
    return 0;
}

/*
Using Floyd's Algorithm or Tortoise-Hare Approach
https://leetcode.com/problems/linked-list-cycle/
*/