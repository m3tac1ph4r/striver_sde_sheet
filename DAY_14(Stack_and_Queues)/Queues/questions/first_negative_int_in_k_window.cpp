#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K)
{
    deque<ll int> dq;
    vector<ll> ans;
    
    // finding -ve element in first k window
    for(int i=0;i<K;i++)
    {
        if(A[i]<0)
        {
            dq.push_back(i);
            break;
        }
    }

    //storing answer of first k window
    if(dq.size()==0)
        ans.push_back(0);
    else
    {
        ans.push_back(A[dq.front()]);
    }
    
    // processing for remaining elements
    for(int i=K;i<N;i++)
    {
        if(!dq.empty() and (i-dq.front()>=K))
        {
            dq.pop_front();
        }
    }

}
int main()
{
    ll int n,k;
    cin>>n>>k;
    ll int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    vector<ll> ans=printFirstNegativeInteger(A,n,k);
    return 0;
}