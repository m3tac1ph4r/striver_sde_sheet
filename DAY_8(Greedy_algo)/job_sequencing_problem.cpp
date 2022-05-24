#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

struct Job{
    int id;
    int dead;
    int profit;    
};

bool comp(Job a,Job b)
{
    return a.profit>b.profit;
}
vector<int> JobScheduling(Job arr[],int n)
{
    int max_dead=arr[0].dead;
    for(int i=1;i<n;i++)
        max_dead=max(max_dead,arr[i].dead);
    vector<int> days(max_dead+1,-1);
    int profit=0,j_done=0;
    sort(arr,arr+n,comp);
    for(int i=0;i<n;i++)
    {
        for(int j=arr[i].dead;j>=1;j--)
        {
            if(days[j]==-1)
            {
                days[j]=arr[i].id;
                profit+=arr[i].profit;
                j_done++;
                break;
            }
        }
    }
    vector<int> ans(2);
    ans[0]=j_done;
    ans[1]=profit;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    Job arr[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i].id>>arr[i].dead>>arr[i].profit;
    }
    vector<int> ans=JobScheduling(arr,n);
    cout<<ans[0]<<" "<<ans[1]<<"\n";
    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
*/