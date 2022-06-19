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
ListNode *reverse(ListNode *head, int len)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *nexxt;
    int c = 1;
    while (curr != NULL and c <= len)
    {
        nexxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nexxt;
        c++;
    }
    return prev;
}
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (left == right || head == NULL)
        return head;
    ListNode *curr = head;
    ListNode *prev = NULL;
    int k = 1;
    while (curr != NULL and k < left)
    {
        prev = curr;
        curr = curr->next;
        k++;
    }

    ListNode *start = curr;
    while (curr != NULL and k < right)
    {
        curr = curr->next;
        k++;
    }
    ListNode *last = curr->next;
    ListNode *new_head = reverse(start, right - left + 1);

    if (prev != NULL)
    {
        prev->next = new_head;
    }
    curr = new_head;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = last;

    if (left == 1)
        return new_head;
    else
        return head;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/reverse-linked-list-ii/