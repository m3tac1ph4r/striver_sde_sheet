#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

int compareVersion(string version1,string version2)
{
    int len1=version1.length();
    int len2=version2.length();
    int i(0),j(0);
    int n1,n2;
    while (i<len1 || j<len2)
    {
        n1=0;
        n2=0;
        while(i<len1 and version1[i]!='.')
        {
            n1=n1*10+(version1[i]-'0');
            i++;
        }
        while (j < len2 and version2[j] != '.')
        {
            n2 = n2 * 10 + (version2[j] - '0');
            j++;
        }
        if(n1<n2)
            return -1;
        else if(n1>n2)
            return 1;
        i++;
        j++;
    }
    return 0;
}    
int main()
{
    string version1,version2;
    cin>>version1;
    cin>>version2;
    cout<<compareVersion(version1,version2);
    return 0;
}

/*
https://leetcode.com/problems/compare-version-numbers/
*/