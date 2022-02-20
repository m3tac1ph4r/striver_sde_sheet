#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
void deleteMiddle(stack<int> &inputStack,int N)
{
    stack<int> arr;
    for (int i = 0; i < N / 2; i++)
    {
        arr.push(inputStack.top());
        inputStack.pop();
    }
    inputStack.pop();
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        inputStack.push(arr.top());
        arr.pop();
    }
}
int main()
{
    int n;
    cin>>n;
    stack<int> inputStack;
    for(int i=0;i<=n;i++)
    {
        int temp;
        cin>>temp;
        inputStack.push(temp);
    }
    deleteMiddle(inputStack,n);
    for(int i=0;i<n;i++)
    {
        cout<<inputStack.top()<<" ";
        inputStack.pop();
    }
    return 0;
}

/*
https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246
*/
/*
USING RECURSION AND BACKTRACKING

void solve(stack<int> &inputStack,int count,int N)
{
    if(count==N/2)
    {
        inputStack.pop();
        return;
    }
    else
    {
        int num=inputStack.top();
        inputStack.pop();
        solve(inputStack,count+1,N);
        inputStack.push(num);
    }
}

void deleteMiddle(stack<int>&inputStack, int N){
    solve(inputStack,0,N);
}
*/