#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

bool isAnagram(string s, string t)
{
    vector<int> arr(26, 0);
    vector<int> arr1(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        arr[s[i] - 'a']++;
    }
    for (int i = 0; i < t.length(); i++)
    {
        arr1[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != arr1[i])
            return false;
    }
    return true;
}
int main()
{
    string s,t;
    cin>>s;
    cin>>t;
    cout<<isAnagram(s,t);
    return 0;
}

/*
https://leetcode.com/problems/valid-anagram/
*/