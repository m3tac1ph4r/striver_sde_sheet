#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

int findMinimumCost(string str)
{
    stack<char> myStack;
    if(str.length()%2!=0)
        return -1;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='{')
            myStack.push(str[i]);
        else
        {
            if(!myStack.empty() and myStack.top()=='{')
            {
                myStack.pop();
            }
            else
                myStack.push(str[i]);
        }
    }

    //invalid string
    int openCount=0,closeCount=0;

    while(!myStack.empty())
    {
        if(myStack.top()=='{')
            openCount++;
        else
            closeCount++;
        myStack.pop();
    }
    return ((openCount+1)/2+(closeCount+1)/2);
}
int main()
{
    string s;
    cin>>s;
    cout << findMinimumCost(s); 
    return 0;
}

/*
https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770
*/