#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    // Write your code here.
    stack<int> arr;
    int n = myStack.size();
    for (int i = 0; i < n; i++)
    {
        arr.push(myStack.top());
        myStack.pop();
    }
    arr.push(x);
    for (int i = 0; i < n + 1; i++)
    {
        myStack.push(arr.top());
        arr.pop();
    }
    return myStack;
}

int main()
{
    stack<int> myStack;
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        myStack.push(temp);
    }
    stack<int> ans=pushAtBottom(myStack,x);
    for(int i=0;i<n+1;i++)
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    return 0;
}

/*
https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166
*/

/*
USING RECURSION AND BACKTRACKING

void solve(stack<int> &myStack,int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }
    else
    {
        int num = myStack.top();
        myStack.pop();

        // recursive call
        solve(myStack, x);

        // backtracking
        myStack.push(num);
    }
}

stack<int> pushAtBottom(stack<int> &myStack,int x)
{
    solve(myStack,x);
    return myStack;
}

*/