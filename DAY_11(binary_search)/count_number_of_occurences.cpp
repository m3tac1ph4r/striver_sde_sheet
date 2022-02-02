#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

int count(int arr[],int n,int x)
{
    int start=0,end=n-1,c=0;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==x)
        {
            for(int i=mid;i>=0;i--)
            {
                if(arr[i]==x)
                    c++;
            }
            for (int i = mid+1; i<n; i++)
            {
                if (arr[i] == x)
                    c++;
            }
            break;
        }
        else if(arr[mid]<x)
            start=mid+1;
        else
            end=mid-1;
    }
    return c;
}
int main()
{
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<count(arr,n,x);
    return 0;
}