#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
bool isPossible(vector<int> stalls,int mid,int k)
{
    int cowCount=1,lastPos=stalls[0];
    for(int i=1;i<stalls.size();i++)
    {
        if(stalls[i]-lastPos>=mid)
        {
            cowCount++;
            if(cowCount==k)
                return true;
            lastPos=stalls[i];
        }
    }
    return false;
}
int agressiveCows(vector<int> &stalls,int k)
{
    sort(stalls.begin(),stalls.end());
    int start=0,end=stalls[stalls.size()-1],ans;
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        if(isPossible(stalls,mid,k))
        {
            ans=mid;
            start=mid+1;
        }
        else
            end=mid-1;
    }
    return ans;
}    
int main()
{
    ll int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> stalls(n);
        for(int i=0;i<n;i++)
            cin>>stalls[i];
        cout<<agressiveCows(stalls,k)<<"\n";
    }
    
    return 0;
}

/*
https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559
https://www.spoj.com/problems/AGGRCOW/

INPUT:
5 2
4 2 1 3 6

OUTPUT:
5

the largest minimum distance will be 5 when 2 cows are placed at positions {1, 6}.

INPUT:
6 3
0 4 3 7 10 9

OUPUT:
4
the largest minimum distance will be 4 when 3 cows are placed at positions {0, 4, 10}.

We will take start=0 and end=stalls[n-1] and will find the mid. If all cows are successfully placed
at that minimum distance. Now we will increase the start=mid+1. Because we have to find maximum.

*/