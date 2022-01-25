#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

string reverseWords(string s)
{
    string ans="";
    int i=0,n=s.length();
    while(i<n)
    {
        while(i<n and s[i]==' ')
            i++;
        if(i>=n)
            break;
        int j=i+1;
        while(j<n and s[j]!=' ')
            j++;
        string temp=s.substr(i,j-i);
        if(ans.length()==0)
            ans=temp;
        else
            ans=temp+" "+ans;
        i=j+1;
    }
    return ans;
}
int main()
{
    string s;
    getline(cin,s);
    string ans=reverseWords(s);
    cout<<ans;
    return 0;
}

/*
Using Two pointer approach
*/