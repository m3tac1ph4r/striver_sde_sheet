#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

vector<int> maxSlidingWindow(vector<int> &nums,int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if(!dq.empty() and i-k>=dq.front())
            dq.pop_front();
        while(!dq.empty() and nums[dq.back()]<nums[i])
            dq.pop_back();
        dq.push_back(i);
        if(i>=k-1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    vector<int> ans=maxSlidingWindow(nums,k);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}

/*
https://leetcode.com/problems/sliding-window-maximum/

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/
