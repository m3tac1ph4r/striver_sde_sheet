#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
int findFloor(vector<long long> v,long long n,long long x)
{
    long long low = 0, high = n - 1, mid, res = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (v[mid] == x)
            return mid;
        else if (x > v[mid])
        {
            res = mid;
            low = mid + 1;
        }
        else if (x < v[mid])
        {
            high = mid - 1;
        }
    }
    if (v[res] <= x)
        return res;
    else
        return -1;
}    
int main()
{
    ll n,x;
    cin>>n>>x;
    vector<long long> v(n);
    for(ll i=0;i<n;i++)
        cin>>v[i];
    cout<<findFloor(v,n,x);
    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1/#

Input:
N = 7, x = 5
arr[] = {1,2,8,10,11,12,19}
Output: 1

Index of nearest element of x i.e 2
*/