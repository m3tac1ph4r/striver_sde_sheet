#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
bool isPossible(vector<int> &A,int mid,int B)
{
    int student=1;
    int pageSum=0;
    for(int i=0;i<A.size();i++)
    {
        if(pageSum+A[i]<=mid)
        {
            pageSum+=A[i];
        }
        else
        {
            student++;
            if(student>B || A[i]>mid)
                return false;
            pageSum=A[i];
        }
        if(student>B)
            return false;
    }
    return true;
}    
int books(vector<int> &A,int B)
{
    int start=0,sum=0,end=0,ans=-1;
    for(int i=0;i<A.size();i++)
        sum+=A[i];
    end=sum;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isPossible(A,mid,B))
        {
            ans=mid;
            end=mid-1;
        }
        else
            start=mid+1;
    }
    return ans;
}    
int main()
{
    int n,B;
    cin>>n>>B;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin>>A[i];
    cout<<books(A,B);
    return 0;
}