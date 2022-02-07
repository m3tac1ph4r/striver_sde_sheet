#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

int findPeakElement(vector<int> nums)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid > 0 and mid < nums.size() - 1)
        {
            if (nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid - 1] > nums[mid])
            {
                high = mid - 1;
            }
            else if (nums[mid + 1] > nums[mid])
                low = mid + 1;
        }
        else if (mid == 0)
        {
            if (nums[0] > nums[1])
                return 0;
            else
                return 1;
        }
        else if (mid == nums.size() - 1)
        {
            if (nums[nums.size() - 1] > nums[nums.size() - 2])
                return nums.size() - 1;
            else
                return nums.size() - 2;
        }
    }
    return -1;
}
int search_Ascending(vector<int> A,int start,int end,int B)
{
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(A[mid]==B)
            return mid;
        else if(A[mid]<B)
            start=mid+1;
        else
            end=mid-1;
    }
    return -1;
}
int search_Descending(vector<int> A, int start, int end, int B)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (A[mid] == B)
            return mid;
        else if (A[mid] < B)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}
int solve(vector<int> &A,int B)
{
    int peak=findPeakElement(A);
    if(B>A[peak])
        return -1;
    if(B==A[peak])
        return peak;
    else
    {
        int ascending=search_Ascending(A,0,peak-1,B);
        int descending=search_Descending(A,peak,A.size()-1,B);
        if(ascending>-1)
            return ascending;
        else if(descending>-1)
            return descending;
    }
    return -1;
}
int main()
{
    int n,B;
    cin>>n>>B;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin>>A[i];
    cout<<solve(A,B);
    return 0;
}

/*
https://www.interviewbit.com/problems/search-in-bitonic-array/

INPUT: 
7 20
3 9 10 20 17 5 1
OUPUT: 3

Firstly we will find peak element i.e 20. All elements before peak_element are sorted in ascending order
And all elements after peak_element including peak_element are sorted in descending order.

* Now we will implement binary_search in ascending order from 0 to peak-1
* Now we will implement binary_search in descending order from peak to n-1
*/