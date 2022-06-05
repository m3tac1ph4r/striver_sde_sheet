#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;


int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 1; i < k; i++)
        pq.pop();
    return pq.top();
}

int main()
{

    return 0;
}
// https://leetcode.com/problems/kth-largest-element-in-an-array/
//  USING MAX HEAP PRIORITY QUEUE