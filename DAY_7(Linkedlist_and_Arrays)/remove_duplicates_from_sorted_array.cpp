#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
int main()
{
    // USING TWO POINTER APPROACH
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    int i=0;
    for(int j=1;j<n;j++)
    {
        if(nums[i]!=nums[j])
        {
            i++;
            nums[i]=nums[j];
        }
    }
    cout<<(i+1)<<"\n";
    for(auto i:nums)
        cout<<i<<" ";
    return 0;
}
/*
Another Approach Using Hashing :

map<int,int> m;
for(int i=0;i<n;i++)
    m[nums[i]]++;
int c=0;
for(auto i:m)
{
    nums[c++]=i.first;
}
cout<<(c)<<"\n";
for(auto i:nums)
    cout<<i<<" ";

*/