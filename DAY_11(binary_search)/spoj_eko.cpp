#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

bool woodRequired(vector<int> tree,int mid,int m,int n)
{
    int wood_collect=0;
    for(int i=0;i<n;i++)
    {
        if(tree[i]>=mid)
            wood_collect+=tree[i]-mid;
        else if(wood_collect>=m)
            return true;
    }
    if(wood_collect>=m)
        return true;
    else
        return false;
}  
int solve(vector<int> tree,int n,int m)
{
    int low=0,high=0,ans;
    high=*max_element(tree.begin(),tree.end());
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if(woodRequired(tree,mid,m,n))
        {
            ans=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }
    return ans;
}    
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> tree(n);
    for(int i=0;i<n;i++)
        cin>>tree[i];
    cout<<solve(tree,n,m)<<"\n";
    return 0;
}

/*
https://www.spoj.com/problems/EKO/
*/