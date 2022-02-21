#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

void insert_sorted(stack<int> &stack,int ele)
{
    if(stack.empty())
    {
        stack.push(ele);
        return;
    }
    else
    {
        int num=stack.top();
        if(num<ele)
        {
            stack.push(ele);
        }
        else
        {
            stack.pop();
            insert_sorted(stack,ele);
            stack.push(num);
        }
    }
}
void sortStack(stack<int> &stack)
{
    if(stack.empty())
        return;
    else
    {
        int num=stack.top();
        stack.pop();
        sortStack(stack);
        insert_sorted(stack,num);
    }
    
}    
int main()
{
    int n;
    cin >> n;
    stack<int> myStack;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        myStack.push(num);
    }
    sortStack(myStack);
    for (int i = 0; i < n; i++)
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    return 0;
}

/*
https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275
*/