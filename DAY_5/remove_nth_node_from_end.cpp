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

ListNode* removeNthFromEnd(ListNode* head,int n)
{
    ListNode* dummy=new ListNode();
    dummy->next=head;
    // dummy= head;
    ListNode* slow=dummy;
    ListNode* fast=dummy;
    for(int i=0;i<n;i++)
    {
       fast=fast->next; 
    }
    while (fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return dummy->next;
    
}
int main()
{
    int n;
    cin >> n;
    ListNode* head=new ListNode(1);
    insertTail(head,2);
    insertTail(head, 3);
    insertTail(head, 4);
    insertTail(head, 5);
    display(head);
    ListNode* newhead=removeNthFromEnd(head,n);
    display(newhead);
    return 0;
}