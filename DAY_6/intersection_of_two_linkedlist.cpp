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
    cout<<"\n";
}
ListNode* getIntersectionNode(ListNode* headA,ListNode* headB)
{
    unordered_set<ListNode*> s;
    while(headA!=NULL)
    {
        s.insert(headA);
        headA=headA->next;
    }
    while(headB!=NULL)
    {
        if((s.find(headB)!=s.end()) and headB!=NULL)
        {
            return headB;
        }
        else
        {
            headB=headB->next;
        }
    }
    return NULL;
}
int main()
{
    return 0;
}

/*
SOLVED THE ABOVE PROBLEM USING HASHING.
https://leetcode.com/problems/intersection-of-two-linked-lists/
*/