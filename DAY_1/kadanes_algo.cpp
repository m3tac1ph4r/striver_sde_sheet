#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
int main()
{
    // vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums = {-2,1};
    int sum=0,max_sum=INT_MIN;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        if(sum>max_sum)
            max_sum=sum;
        else if(sum<0)
            sum=0;
    }
    sum=0;
    for (int i = nums.size()-1; i >=0; i--)
    {
        sum += nums[i];
        if (sum > max_sum)
            max_sum = sum;
        else if (sum < 0)
            sum = 0;
    }
    cout<<max_sum;
    return 0;
}