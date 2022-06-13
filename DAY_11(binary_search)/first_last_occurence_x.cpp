#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int firstOccur(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1, ans1 = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            ans1 = mid;
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans1;
}
int lastOccur(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1, ans2 = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            ans2 = mid;
            low = mid + 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans2;
}
vector<int> firstAndLast(vector<int> &arr, int n, int x)
{
    vector<int> ans;
    ans.push_back(firstOccur(arr, n, x));
    if (ans[0] != -1)
        ans.push_back(lastOccur(arr, n, x));
    return ans;
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans = firstAndLast(arr, n, x);
    for (int i = 0; i < 2; i++)
        cout << ans[i] << " ";
    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x2041/1/#
*/