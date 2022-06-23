#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int findKRotation(int arr[], int n)
{
    int low = 0, high = n - 1, res = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int prev = mid - 1;
        int next = (mid + 1);
        if (mid == 0)
        {
            prev = n - 1;
            next = 1;
        }
        else if (mid == n - 1)
        {
            prev = n - 2;
            next = 0;
        }
        if (arr[mid] <= arr[prev] and arr[mid] <= arr[next])
        {
            return mid;
        }
        else if (arr[low] <= arr[mid] and arr[mid] >= arr[high])
            low = mid + 1;
        else if (arr[mid] <= arr[high])
            high = mid - 1;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findKRotation(arr, n);
    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/rotation4723/1/#

In: {5, 1, 2, 3, 4}

Divided the array in two half a)sorted  b)non-sorted

low=0   high=4  mid=2
{2,3,4} is sorted and {5,1,2} is non-sorted
We have to find the unsorted array bcz answer lies in that portion.

We have to find that element whose previous is also small and next also.

1<5 and 1<2 so both are true. So index of 1 is our answer

*/