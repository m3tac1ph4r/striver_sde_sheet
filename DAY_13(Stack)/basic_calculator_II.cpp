#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
int calculate(string s)
{
    int res=0;
    stack<int> myStack;
    int currentNumber=0;
    char operation='+';
    int len=s.length();
    if(s.length()==0)
        return 0;
    for(int i=0;i<s.length();i++)
    {
        char currentChar=s[i];
        if(isdigit(currentChar))
        {
            currentNumber=(currentNumber*10)+(currentChar-'0');
        }
        if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1)
        {
            if(operation=='+')
            {
                myStack.push(currentNumber);
            }
            else if(operation=='-')
                myStack.push(-currentNumber);
            else if(operation=='*')
            {
                int stackTop=myStack.top();
                myStack.pop();
                myStack.push(stackTop*currentNumber);
            }
            else if(operation=='/')
            {
                int stackTop=myStack.top();
                myStack.pop();
                myStack.push(stackTop/currentNumber);
            }
            operation=currentChar;
            currentNumber=0;
        }
    }
    while(!myStack.empty())
    {
        res+=myStack.top();
        myStack.pop();
    }
    return res;
}    
int main()
{
    string s;
    cin>>s;
    cout<<calculate(s);
    return 0;
}

/*
https://leetcode.com/problems/basic-calculator-ii/

If the currentChar is digit then store it to currentNumber
if the curentChar is operation then it will do the last operation and update the currentNumber and currentChar

For example: 3+2*2
i=0
    currentNumber:3
    currentChar: 3
    operation:+(at intialization)
    Stack: {}

i=1
    currentNumber:3,0(number will be updated in last)
    currentChar:+
    operation:+
    Stack:{3}

i=2
    currentNumber:2
    currentChar:2
    operation:+
    Stack:{3}

i=3
    currentNumber:*
    currentChar:*
    operation:+,*
    Stack:{2 3}

i=4
    currentNumber:2
    currentChar:2
    operation:*
    Stack:{4 3}
*/