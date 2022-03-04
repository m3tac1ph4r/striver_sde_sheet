#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
string removeKdigits(string num,int k)
{
    string ans="";
    stack<char> myStack;
    if(num.length()<=k)
        return "0";
    for(int i=0;i<num.size();i++)
    {
        if(myStack.empty())
            myStack.push(num[i]);
        else
        {
            while(!myStack.empty() and myStack.top()>num[i] and k>0)
            {
                myStack.pop();
                k--;
            }
            myStack.push(num[i]);
        }
    }
    while (k>0)
    {
        myStack.pop();
        k--;
    }
    
    while(!myStack.empty())
    {
        ans=myStack.top()+ans;
        myStack.pop();
    }
    int l=0;
    for(int i=0;i<ans.length();i++)
    {
        if(ans[i]!='0')
            break;
        else
            l++;
    }
    ans = (ans.substr(l) == "") ? "0" : ans.substr(l);
    return ans;
}    
int main()
{
    string num;
    int k;
    cin>>num>>k;
    cout<<removeKdigits(num,k);
    return 0;
}

/*
https://leetcode.com/problems/remove-k-digits/
*/