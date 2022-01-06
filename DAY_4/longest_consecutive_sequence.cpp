#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
int longestConsecutive(vector<int> &nums)
{
    if(nums.size()==0)
        return 0;
    sort(nums.begin(),nums.end());
    int len=1;
    int max_len=0;
    int k=nums[0]+1;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]==nums[i-1])
        {
            continue;
        }
        else if(nums[i]!=k)
        {
            max_len=max(len,max_len);
            len=1;
            k=nums[i]+1;
        }
        else
        {
            len++;
            k++;
        }
    }
    max_len=max(len,max_len);
    return max_len;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int &i:nums)
        cin>>i;
    cout<<longestConsecutive(nums);
    return 0;
}