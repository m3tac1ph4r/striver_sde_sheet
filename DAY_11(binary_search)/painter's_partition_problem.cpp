#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

bool isPossible(vector<int> boards, int k, int mid)
{
    int paintersCount = 1, sum = 0;
    for (int i = 0; i < boards.size(); i++)
    {
        if (sum + boards[i] <= mid)
        {
            sum += boards[i];
        }
        else
        {
            paintersCount++;
            if (paintersCount > k || boards[i] > mid)
                return false;
            sum = boards[i];
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> boards, int k)
{
    int start = 0, sum = 0, end, ans = -1;
    if (k > boards.size())
        return -1;
    for (int i = 0; i < boards.size(); i++)
        sum += boards[i];
    end = sum;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(boards, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> boards(n);
    for (int i = 0; i < n; i++)
        cin >> boards[i];
    cout << findLargestMinDistance(boards, k);
    return 0;
}
/*
https://www.codingninjas.com/codestudio/problems/painter-s-partition-problem_1089557
*/