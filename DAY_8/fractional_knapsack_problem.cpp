#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

struct Item{
    int value;
    int weight;
};
bool comp(Item a,Item b)
{
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;
}
double fractionalKnapsack(int W,Item arr[],int n)
{
    double ans=0;
    sort(arr,arr+n,comp);
    for(int i=0;i<n;i++)
    {
        if(arr[i].weight<=W)
        {
            ans+=arr[i].value;
            W=W-arr[i].weight;
        }
        else
        {
            double r=(double)arr[i].value/arr[i].weight;
            ans+=r*W;
            W=0;
            break;
        }
    }
    return ans;
}
int main()
{
    int n,W;
    cin>>n;
    cin>>W;
    Item arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].value>>arr[i].weight;
    }
    cout<<fractionalKnapsack(W,arr,n);
    return 0;
}