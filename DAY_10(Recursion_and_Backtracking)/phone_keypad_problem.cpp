#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

void solve(int n,int index,string digit,vector<string> &ans,string s,string arr[])    
{
    if(index==n)
    {
        ans.push_back(s);
        return;
    }
    else
    {
        int number=digit[index]-'0';
        string val=arr[number];
        for(int i=0;i<val.length();i++)
        {
            s.push_back(val[i]);
            solve(n,index+1,digit,ans,s,arr);
            s.pop_back();
        }
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if(digits.length()==0)
        return ans;
    string arr[10];
    arr[0]="";
    arr[1]="";
    arr[2]="abc";
    arr[3]="def";
    arr[4]="ghi";
    arr[5]="jkl";
    arr[6]="mno";
    arr[7]="pqrs";
    arr[8] = "tuv";
    arr[9] = "wxyz";
    solve(digits.length(),0,digits,ans,"",arr);
    return ans;
}    
int main()
{
    string digits;
    cin>>digits;
    vector<string> ans=letterCombinations(digits);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<"\n";
    return 0;
}