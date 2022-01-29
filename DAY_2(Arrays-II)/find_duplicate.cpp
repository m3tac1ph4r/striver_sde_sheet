#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
int findDuplicate(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    int dup;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            dup = nums[i];
            break;
        }
    }
    return dup;
}    
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i=0;i<=n;i++)
    {
        cin>>nums[i];
    }
    cout<<findDuplicate(nums);
    return 0;
}