#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int maximumProduct(vector<int> &arr, int n)
{
    int maxp = INT_MIN, product = 1;
    for (int i = 0; i < n; i++)
    {
        product *= arr[i];
        maxp = max(maxp, product);
        if (product == 0)
            product = 1;
    }
    product = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        product *= arr[i];
        maxp = max(maxp, product);
        if (product == 0)
            product = 1;
    }
    return maxp;
}
int main()
{

    return 0;
}
// https://leetcode.com/problems/maximum-product-subarray/
// Using Kaden's Algo