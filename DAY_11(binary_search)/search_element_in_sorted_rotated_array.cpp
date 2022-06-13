#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[low] <= nums[mid]) // check whtther the left array is sorted or not [left,mid]
        {
            if (target <= nums[mid] and target >= nums[low])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else // right part is sorted [mid,high]
        {
            if (target >= nums[mid] and target <= nums[high])
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cin >> target;
    cout << search(nums, target);
    return 0;
}

/*
https://leetcode.com/problems/search-in-rotated-sorted-array/

Using Binary Search

TC: O(logn)
SC: O(1)

*/

/*
Naive Appraoch:
TC: O(n)
SC: O(1)

int search(vector<int>& nums, int target) {
    int ans=-1;
    for(int i=0;i<nums.size();i++)
    {
        if(target==nums[i])
        {
            ans=i;
            break;
        }
    }
    return ans;
}
*/