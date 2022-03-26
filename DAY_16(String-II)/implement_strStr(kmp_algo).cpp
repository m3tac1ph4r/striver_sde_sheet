#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
vector<int> prefix_function(string haystack)
{
    int j;
    vector<int> pi(haystack.length(),0);
    for(int i=1;i<haystack.length();i++)
    {
        j=pi[i-1];
        while(j>0 and haystack[i]!=haystack[j])
            j=pi[j-1];
        if(haystack[i]==haystack[j])
            j++;
        pi[i]=j;
    }
    return pi;
}    
int strStr(string haystack,string needle)
{
    if (needle.length() == 0)
        return 0;
    if (haystack.length() == 0)
        return -1;
    if (needle.length() > haystack.length())
        return -1;
    string new_s=needle+"#"+haystack;
    vector<int> pi=prefix_function(new_s);
    for(int i=0;i<pi.size();i++)
    {
        if(pi[i]==needle.length())
            return i-2*needle.length();
    }
    return -1;
}
int main()
{
    string haystack,needle;
    cin>>haystack;
    cin>>needle;
    cout<<strStr(haystack,needle);
    return 0;
}

/*
https://leetcode.com/problems/implement-strstr/

Solved Using KMP Algorithm
https://cp-algorithms.com/string/prefix-function.html
*/