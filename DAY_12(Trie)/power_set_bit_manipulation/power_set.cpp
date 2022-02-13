#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

vector<string> AllPossibleStrings(string s)
{
    vector<string> ans;
    int n=pow(2,s.length());
    for(int i=1;i<=n-1;i++)
    {
        int x=i;
        string c="";
        int j=0;
        while(x)
        {
            if(x&1)
            {
                c=c+s[j];
            }
            j++;
            x=x>>1;
        }
        ans.push_back(c);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string s;
    cin>>s;
    vector<string> ans = AllPossibleStrings(s);
    for(string i:ans)
        cout<<i<<"\n";
    return 0;
}
/*
https://practice.geeksforgeeks.org/problems/power-set4302/1#
*/