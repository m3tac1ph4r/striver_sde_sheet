#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

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

/*
The below function will only reverse  k nodes
input: 1 2 3 4 5   K=3
output: 3 2 1 4 5
*/
ListNode *reverse(ListNode *head, int k, int length)
{
    if (length < k)
        return head;
    ListNode *next_p;
    ListNode *prev = NULL;
    ListNode *curr = head;
    int c = 0;
    int count = 0;
    ListNode *temp = head;
    while (curr != NULL and c < k)
    {
        next_p = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_p;
        c++;
    }
    if (curr != NULL)
    {
        head->next = reverse(next_p, k, length - k);
    }
    return prev;
}

/*
The below function will reverse less than k nodes also
input: 1 2 3 4 5 K=3
output: 3 2 1 5 4
*/
ListNode *reverse(ListNode *head, int k)
{
    ListNode *next_p;
    ListNode *prev = NULL;
    ListNode *curr = head;
    int c = 0;
    int count = 0;
    ListNode *temp = head;
    while (curr != NULL and c < k)
    {
        next_p = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_p;
        c++;
    }
    if (curr != NULL)
    {
        head->next = reverse(next_p, k);
    }
    return prev;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return reverse(head, k, length);
    // return reverse(head, k);
}
int main()
{
    ListNode *head = NULL;
    insertTail(head, 1);
    insertTail(head, 2);
    insertTail(head, 3);
    insertTail(head, 4);
    insertTail(head, 5);
    display(head);
    ListNode *temp = reverseKGroup(head, 3);
    display(temp);
    return 0;
}

/*
https://leetcode.com/problems/reverse-nodes-in-k-group/
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
*/