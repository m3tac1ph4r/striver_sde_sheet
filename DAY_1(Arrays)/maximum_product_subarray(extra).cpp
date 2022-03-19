#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
int maxProduct(vector<int> nums)
{
    int ma=nums[0];
    int mi=nums[1];
    int ans=INT_MIN;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]<0)
        {
            int temp=ma;
            ma=mi;
            mi=temp;
        }
        ma=max(nums[i],ma*nums[i]);
        mi=min(nums[i],nums[i]*mi);
        ans=max(ans,ma);
    }
    return ans;
}    
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    cout<<maxProduct(nums);
    return 0;
}

/*
https://leetcode.com/problems/maximum-product-subarray/
*/

/*
Another Approach Using Kaden's algo

int maxProduct(vector<int>& nums) {
        int product=1;
        int max_product=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            product=product*nums[i];
            max_product=max(product,max_product);
            if(product==0)
                product=1;
        }
        product=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            product=product*nums[i];
            max_product=max(product,max_product);
            if(product==0)
                product=1;
        }
        return max_product;
    }
*/