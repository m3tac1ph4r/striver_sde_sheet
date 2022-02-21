#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

void insertAtBottom(stack<int> &stack, int ele)
{
    if (stack.empty())
    {
        stack.push(ele);
        return;
    }
    else
    {
        int num = stack.top();
        stack.pop();
        insertAtBottom(stack, ele);
        stack.push(num);
    }
}
void reverseStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
        return;
    else
    {
        int num = stack.top();
        stack.pop();
        reverseStack(stack);
        insertAtBottom(stack, num);
    }
}

int main()
{
    int n;
    cin>>n;
    stack<int> myStack;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        myStack.push(num);
    }
    reverseStack(myStack);
    for(int i=0;i<n;i++)
    {
        cout<<myStack.top()<<" ";
        myStack.pop();
    }
    return 0;
}

/*
https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875
*/