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
        string c="";
        for(int j=0;j<s.length();j++)
        {
            int a=1<<j;
            int b=i&1<<j;
            cout<<"i"<<i<<" j"<<j<<" 1<<j "<<a<<" "<<b<<"\n";
            if(i&(1<<j))
            {
                c=c+s[j];
            }
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

/*
WORKING OF PROGRAM IS:

1<<j    means shifting 1 to left j times in 001

WHEN i=1   
and  j=0
    001
    001
    ---
    001 ->1 which is true now "a" is added

    j=1
    001
    010
    ---
    000 ->0 which is false

WHEN i=2
AND  j=0
    010
    001
    ---
    000 ->0 which is false

    j=1
    010
    010
    ---
    010 ->2 which is true "b" is added

*/