#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
int main()
{
    vector<int> nums={1,3,2};
    if(next_permutation(nums.begin(),nums.end()))
    {
        for (auto i : nums)
            cout << i << " ";
    }
    else
    {
        sort(nums.begin(),nums.end());
        for (auto i : nums)
            cout << i << " ";
    }
    return 0;
}