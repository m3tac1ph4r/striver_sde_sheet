#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

int strStr(string haystack, string needle)
{
    if (needle.length() == 0)
        return 0;
    if (haystack.length() == 0)
        return -1;
    if(needle.length()>haystack.length())
        return -1;
    int p = 31;
    int M = 1e9 + 7;
    vector<long long> power(haystack.length() + 1);
    vector<long long> hash_text(haystack.length() + 1, 0);
    long long hash_pattern = 0;
    power[0] = 1;
    for (int i = 1; i < haystack.length() + 1; i++)
    {
        power[i] = (power[i - 1] * p) % M;
    }
    for (int i = 0; i < haystack.length(); i++)
    {
        hash_text[i + 1] = (hash_text[i] + (haystack[i] - 'a' + 1) * power[i]) % M;
    }
    for (int i = 0; i < needle.length(); i++)
    {
        hash_pattern = (hash_pattern + (needle[i] - 'a' + 1) * power[i]) % M;
    }
    for (int i = 0; i + needle.length() - 1 < haystack.length(); i++)
    {
        long long curr_hash = (hash_text[i + needle.length()] - hash_text[i] + M) % M;
        if (curr_hash == ((hash_pattern)*power[i])%M)
            return i;
    }
    return -1;
}
int main()
{
    string text,pattern;
    cin>>text;
    cin>>pattern;
    cout<<strStr(text,pattern);
    return 0;
}

/*
https://leetcode.com/problems/implement-strstr/

Solved Using Rabin Karp String Searching Algorithm
Input: haystack = "hello", needle = "ll"
Output: 2
*/