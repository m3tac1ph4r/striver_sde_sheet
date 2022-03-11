#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

queue<int> rev(queue<int> q)
{
    stack<int> myStack;
    while (!q.empty())
    {
        int num = q.front();
        myStack.push(num);
        q.pop();
    }
    while (!myStack.empty())
    {
        q.push(myStack.top());
        myStack.pop();
    }
    return q;
}
int main()
{
    
    return 0;
}