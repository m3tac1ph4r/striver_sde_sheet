#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next_p;
    while (curr != NULL)
    {
        next_p = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_p;
    }
    head = prev;
    return head;
}
vector<int> nextLargerNodes(ListNode *head)
{
    stack<int> myStack;
    vector<int> ans;
    ans.push_back(0);
    ListNode *temp = reverseList(head);
    while (temp != NULL)
    {
        if (myStack.empty())
            myStack.push(temp->val);
        else
        {
            if (myStack.top() > temp->val)
            {
                ans.push_back(myStack.top());
            }
            else if (myStack.top() <= temp->val)
            {
                while (myStack.empty() == false and myStack.top() <= temp->val)
                {
                    myStack.pop();
                }
                if (myStack.empty() or myStack.top() == temp->val)
                {
                    ans.push_back(0);
                }
                else if (myStack.top() > temp->val)
                    ans.push_back(myStack.top());
            }
            myStack.push(temp->val);
        }
        temp = temp->next;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    
    return 0;
}

/*
https://leetcode.com/problems/next-greater-node-in-linked-list/
*/