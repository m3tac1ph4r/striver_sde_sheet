#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K)
{
    deque<long long int> dq;
    vector<long long> ans;
    
    // finding -ve element in first k window
    for(int i=0;i<K;i++)
    {
        if(A[i]<0)
        {
            dq.push_back(i);
        }
    }

    //storing answer of first k window
    if(dq.size()>0)
        ans.push_back(A[dq.front()]);
    else
    {
        ans.push_back(0);
    }
    
    // processing for remaining elements
    for(int i=K;i<N;i++)
    {
        //removal of element
        if (!dq.empty() and (i-K >= dq.front()))
        {
            dq.pop_front();
        }

        // adding the answer to dq
        if(A[i]<0)
        {
            dq.push_back(i);
            // break;
        }
        if(dq.size()>0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
            ans.push_back(0);
    }
    return ans;
}
int main()
{
    ll int n,k;
    cin>>n>>k;
    ll int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    vector<ll> ans=printFirstNegativeInteger(A,n,k);
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}