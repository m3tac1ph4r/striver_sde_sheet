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

ListNode *addTwoNumbers(ListNode *head1, ListNode *head2)
{
    int carry = 0, sum = 0;
    ListNode *res = new ListNode();
    ListNode *dummy = res;
    ListNode *l1 = head1;
    ListNode *l2 = head2;
    while (l1 != NULL and l2 != NULL)
    {
        if (carry > 0)
        {
            sum = l1->val + l2->val + carry;
            carry = 0;
        }
        else
            sum = l1->val + l2->val;
        if (sum >= 10)
        {
            carry = sum / 10;
            sum = sum % 10;
        }
        // insertTail(res,sum);
        ListNode *temp = new ListNode(sum);
        res->next = temp;
        res = res->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL)
    {
        if (carry > 0)
        {
            sum = l1->val + carry;
            carry = 0;
        }
        else
            sum = l1->val;
        if (sum >= 10)
        {
            carry = sum / 10;
            sum = sum % 10;
        }
        // insertTail(res,sum);
        ListNode *temp = new ListNode(sum);
        res->next = temp;
        res = res->next;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        if (carry > 0)
        {
            sum = l2->val + carry;
            carry = 0;
        }
        else
            sum = l2->val;
        if (sum >= 10)
        {
            carry = sum / 10;
            sum = sum % 10;
        }
        // insertTail(res, sum);
        ListNode *temp = new ListNode(sum);
        res->next = temp;
        res = res->next;
        l2 = l2->next;
    }
    if (carry > 0)
    {
        // insertTail(res,carry);
        ListNode *temp = new ListNode(carry);
        res->next = temp;
        res = res->next;
    }
    return res->next;
}
int main()
{
    int i, n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < m; i++)
        cin >> b[i];
    ListNode *head1 = new ListNode(a[0]);
    ListNode *head2 = new ListNode(b[0]);
    for (i = 1; i < n; i++)
        insertTail(head1, a[i]);
    for (i = 1; i < m; i++)
        insertTail(head2, b[i]);
    display(head1);
    display(head2);
    ListNode *res = addTwoNumbers(head1, head2);
    display(res);
    return 0;
}

/*
https://leetcode.com/problems/add-two-numbers/
*/