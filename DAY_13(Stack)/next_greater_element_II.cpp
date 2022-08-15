#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;
vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
        st.push(nums[i]);

    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] < st.top())
            ans[i] = st.top();
        else if (nums[i] >= st.top())
        {
            while (st.empty() == false and st.top() <= nums[i])
                st.pop();
            if (st.empty() == true)
                ans[i] = -1;
            else if (st.top() > nums[i])
                ans[i] = st.top();
        }
        st.push(nums[i]);
    }
    return ans;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/next-greater-element-ii/