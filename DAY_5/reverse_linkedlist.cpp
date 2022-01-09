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
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* next_p;
    while(curr!=NULL)
    {
        next_p=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next_p;
    }
    head=prev;
    return head;
}
void insertTail(ListNode* &head,int val)
{
    ListNode* tmp=new ListNode(val);
    if(head==NULL)
        head=tmp;
    else
    {
        ListNode* n=head;
        while(n->next!=NULL)
        {
            n=n->next;
        }
        n->next=tmp;
    }
    
}
void display(ListNode* head)
{
    while (head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    
}
int main()
{
    ListNode* head=new ListNode();
    insertTail(head,1);
    insertTail(head, 2);
    insertTail(head, 3);
    insertTail(head, 4);
    display(head);
    ListNode* temp=reverseList(head);
    display(temp);
    return 0;
}