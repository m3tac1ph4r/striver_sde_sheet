#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

int findPlatform(int arr[],int dep[],int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);
    int platform=1,i=1,j=0;
    while (i<n and j<n)
    {
        if (arr[i]<=dep[j])
            platform++;
        else
            j++;
        i++;       
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