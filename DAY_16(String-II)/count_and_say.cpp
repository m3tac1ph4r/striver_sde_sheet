#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
string countAndSay(int n)
{
    if(n==1)
        return "1";
    if(n==2)
        return "11";
    if(n==3)
        return "21";
    string s="21";
    for(int i=4;i<=n;i++)
    {
        string t="";
        s=s+"$";
        int c=1;
        for(int j=1;j<s.length();j++)
        {
            if(s[j]!=s[j-1])
            {
                t=t+to_string(c);
                t=t+s[j-1];
                c=1;
            }
            else
                c++;
        }
        s=t;
    }
    return s;
}    
int main()
{
    int n;
    cin>>n;
    cout<<countAndSay(n);
    return 0;
}

/*
https://leetcode.com/problems/count-and-say/
*/
/*
Firstly we will check the base case for 1,2,3 .
Suppose n=4
In first for loop it will use for ith iteration and we will add "$" delimeter so that we can check till last element of s
In second for loop we will check whether s[j]==s[j-1] means same character then increase count . Else add count to string t and then add s[j-1] to string t

Suppose n=4
s="21$"
i=4
    t=""
    c=1
    j=1
        s[j-1]!=s[j](2!=1)
        t=t+c       // "1"
        t=t+s[j-1]  //"12"
    j=2
        s[j-1]!=s[j](1!=$)
        t=t+c       //"12"+"1" => "121"
        t=t+s[j-1]  //"121"+"1" => "1211"

*/