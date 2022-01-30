#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
int maxLen(vector<int> &A,int n)
{
    unordered_map<int,int> m;
    int sum=0,max_len=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if(sum==0)
        {
            max_len=i+1;
        }
        else
        {
            if(m.find(sum)!=m.end())
            {
                max_len=max(max_len,i-m[sum]);
            }
            else
                m[sum]=i;
        }
    }
    return max_len;
}
int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int &i:A)
        cin>>i;
    cout<<maxLen(A,n);
    return 0;
}