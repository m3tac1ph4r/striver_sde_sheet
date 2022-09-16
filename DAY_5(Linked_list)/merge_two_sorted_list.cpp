#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *res = new ListNode(-1);
    ListNode *p1 = list1;
    ListNode *p2 = list2;
    ListNode *p3 = res;
    while (p1 != NULL and p2 != NULL)
    {
        if (p1->val <= p2->val)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    if (p1 != NULL)
    {
        p3->next = p1;
    }
    if (p2 != NULL)
    {
        p3->next = p2;
    }
    return res->next;
}

ListNode *mergeRecursive(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    ListNode *res;
    if (list1->val < list2->val)
    {
        res = list1;
        res->next = mergeRecursive(list1->next, list2);
    }
    else
    {
        res = list2;
        res->next = mergeRecursive(list1, list2->next);
    }
    return res;
}

int main()
{
    ListNode *l1 = new ListNode();
    ListNode *l2 = new ListNode();
    insertTail(l1, -9);
    insertTail(l1, 3);
    insertTail(l2, 5);
    insertTail(l2, 7);
    display(l1);
    display(l2);
    // ListNode* res=mergeTwoLists(l1,l2);
    ListNode *res = mergeRecursive(l1, l2);
    display(res);
    return 0;
}