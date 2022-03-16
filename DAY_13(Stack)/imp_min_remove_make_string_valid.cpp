#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

string minRemoveToMakeValid(string s)
{
    string ans="";
    stack<int> myStack;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
            myStack.push(i);
        else if(s[i]==')' and myStack.empty())
            s[i]='#';
        else if(s[i]==')' and s[myStack.top()]=='(')
            myStack.pop();
    }
    while (!myStack.empty())
    {
        s[myStack.top()]='#';
        myStack.pop();
    }
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='#')
            ans+=s[i];
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout << minRemoveToMakeValid(s);
    return 0;
}

/*
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
*/

/*
In the above program we used stack and check
1. s[i]=='(' then push the index into the stack
2. s[i]==')' then we have two options 
    a) if stack is empty means this is extra closing bracket replace it will '#' so that we can remember that
    b) if stack is not empty means it is paired so simply pop '(' from the stack.

Then after traversing s if stack is not empty it means stack is having extra opening bracket.
*/