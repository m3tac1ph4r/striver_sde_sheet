#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
int myAtoi(string s)
{
    int i=0,sign=+1,n=s.length();
    long ans = 0;
    while (i < n and s[i] == ' ')
        i++;
    s=s.substr(i);
    if(s[0]=='-')
        sign=-1;
    i=(s[0]=='-'||s[0]=='+')?1:0;
    while(i<n)
    {
        if(s[0]==' '||!isdigit(s[i]))
            break;
        ans=ans*10+(s[i]-'0');
        if(sign==-1 and -1*ans<INT_MIN)
            return INT_MIN;
        if(sign==1 and 1*ans>INT_MAX)
            return INT_MAX;
        i++;   
    }
    return (sign*ans);    
}    
int main()
{
    string s;
    getline(cin,s);
    cout<<myAtoi(s);   
    return 0;
}