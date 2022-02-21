#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

bool findRedundantBrackets(string &s)
{
    stack<char> myStack;
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        if (ch == '(' or ch == '+' or ch == '-' or ch == '*' or ch =='/')
            myStack.push(ch);
        else if(ch==')' and myStack.empty()==false)
        {
            if (myStack.top() == '+' or myStack.top() == '-' or myStack.top() == '*' or myStack.top() == '/')
            {
                while(myStack.top()!='(')
                {
                    myStack.pop();
                }
                myStack.pop();
                continue;
            }
            else
                return true;
        }
        else
            continue;
    }
    return false;
}
int main()
{
    string s;
    cin>>s;
    findRedundantBrackets(s)==false?cout<<"NO"<<"\n":cout<<"YES"<<"\n";
    return 0;
}