#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

double multiply(double number, int n)
{
    double ans = 1.0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * number;
    }
    return ans;
}
double findNthRootOfM(int n,long long m)
{
    double low=1,high=m;
    double eps = 1e-6;
    while ((high - low) > eps)
    {
        double mid = (low + high) / 2.0;
        if (multiply(mid, n) < m)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}
int main()
{
    int n;
    long long m;
    cin>>n;
    cin>>m;
    cout<<findNthRootOfM(n,m);
    return 0;
}