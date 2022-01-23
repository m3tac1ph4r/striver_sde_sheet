#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

void solve(int i,vector<int> arr,int n,int sum,vector<int> &ans)
{
    if(i==n)
    {
        ans.push_back(sum);
        return;
    }
    else
    {
        solve(i+1,arr,n,sum+arr[i],ans);    //element added to sum
        solve(i+1, arr, n, sum, ans);      //element not added to sum
    }
}
vector<int> subsetSums(vector<int> arr,int n)
{
    vector<int> ans;
    solve(0,arr,n,0,ans);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];  
    }
    vector<int> ans=subsetSums(arr,n);
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}