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
ListNode* detectCycle(ListNode* head)
{
    ListNode *res = NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
        return NULL;
    while (slow != NULL and fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            break;
    }
    if (fast != slow)
        return NULL;
    else
    {
        fast = head;
        while (fast->next != slow->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
            res = fast;
        else
            res = fast->next;
        return res;
    }
}
int main()
{
    ListNode* head=NULL;
    return 0;
}

/*
https://leetcode.com/problems/linked-list-cycle-ii/

Above approach is solved using Floyd's ALgorithm
Same as solved in detection and removal of loop in linkedlist cycle
*/