#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

bool comp(vector<int> a,vector<int> b)
{
    return a[1]<b[1];
}
int findPlatform(int arr[],int dep[],int n)
{
    vector<vector<int>> v;
    for(int i=0;i<n;i++)
        v.push_back({arr[i],dep[i]});
    sort(v.begin(),v.end(),comp);
    int platform=1;
    // int i=0,j=1;
    // while(j<n)
    // {
    //     if(v[i][1]<v[j][0])
    //     {
    //         i=j;
    //         j++;
    //     }
    //     else
    //     {
    //         platform++;
    //         j++;
    //     }
    // }
    int end=v[0][1];
    for(int i=1;i<n;i++)
    {
        if(v[i][0]<end)
        {
            platform++;
        }
        end=min(end,v[i][1]);
    }
    return platform;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int dep[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        cin>>dep[i];
    cout<<findPlatform(arr,dep,n);
    return 0;
}