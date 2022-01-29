#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
int main()
{
    vector<int> prices={7,1,5,3,6,4};
    int ele, max_profit = INT_MIN, profit;
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        ele = max(prices[i], ele);
        profit = max(ele - prices[i], 0);
        max_profit = max(profit, max_profit);
    }
    cout<<max_profit;
    return 0;
}