#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

int romanToInt(string s)
{
    int num=0;
    for(int i=0;i<s.length();i++)
    {
        // cout<<num<<"\n";
        char ch=s[i];
        switch (ch)
        {
        case 'I':
            num+=1;
            break;
        case 'V':
            num+=5;
            break;
        case 'X':
            num+=10;
            break;
        case 'L':
            num+=50;
            break;
        case 'C':
            num+=100;
            break;
        case 'D':
            num+=500;
            break;
        case 'M':
            num+=1000;
            break;
        default:
            break;
        }
    }
    for(int i=1;i<s.length();i++)
    {
        // cout<<num<<"\n";
        if(s[i-1]=='C' and (s[i]=='M' or s[i]=='D'))
            num-=200;
        else if (s[i - 1] == 'X' and (s[i] == 'L' or s[i] == 'C'))
            num-=20;
        else if (s[i - 1] == 'I' and (s[i] == 'V' or s[i] == 'X'))
            num-=2;
    }
    return num;
}
int main()
{
    string s;
    getline(cin,s);
    cout<<romanToInt(s);
    return 0;
}
/*
*/
