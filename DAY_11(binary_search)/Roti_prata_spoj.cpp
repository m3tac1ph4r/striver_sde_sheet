#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
bool isPossible(vector<int> arr,int mid,int p)
{
    int total=0;
    for(int i=0;i<arr.size();i++)
    {
        int time=arr[i],timetaken=0,paratha=0,k=1;
        while((timetaken+time*k)<=mid)
        {
            paratha++;
            timetaken+=time*k;
            k++;
        }
        total+=paratha;
        if(total>=p)
            return true;
    }
    return false;
}    
int solve(vector<int> arr,int n,int p)
{
    int low=0,high=INT_MAX;
    int ans=0;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if(isPossible(arr,mid,p))
        {
            ans=mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;    
}    
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int p,n;
        cin>>p;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<solve(arr,n,p)<<"\n";
    }   
    return 0;
}

/*
https://www.spoj.com/problems/PRATA/
*/