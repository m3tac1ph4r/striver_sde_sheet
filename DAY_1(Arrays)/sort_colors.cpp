#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
int main()
{
    vector<int> nums={2,0,2,1,1,0};
    sort(nums.begin(),nums.end());
    for(auto i:nums)
        cout<<i<<" ";
    return 0;
}