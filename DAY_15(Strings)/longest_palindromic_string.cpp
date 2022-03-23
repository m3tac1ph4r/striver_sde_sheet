#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

string longestPalindrome(string s)
{
    string ans;
    int start=0,max_len=1,n=s.length();
    for(int i=1;i<n;i++)
    {
        // For even length
        int low=i-1,high=i;
        while(low>=0 and high<n and s[low]==s[high])
        {
            if(high-low+1>max_len)
            {
                start=low;
                max_len=high-low+1;
            }
            low--;high++;
        }

        //For odd length
        low=i-1;high=i+1;
        while(low>=0 and high<n and s[low]==s[high])
        {
            if((high-low+1)>max_len)
            {
                start=low;
                max_len=high-low+1;
            }
            low--;high++;
        }
    }
    ans=s.substr(start,max_len);
    return ans;
}
int main()
{
    string s;
    getline(cin,s);
    string ans=longestPalindrome(s);
    cout<<ans;
    return 0;
}

/*
https://leetcode.com/problems/longest-palindromic-substring/
Solved using odd even approach
*/

/*
Ex- b a b a d
    0 1 2 3 4

i=1
    low=0,high=2
    start=0,max_len=3

i=2
    low=1,high=3


Ex- c b b d
    0 1 2 3

i=1
    low=0,high=1

i=2
    low=1,high=2
    start=1,max_len=2
*/