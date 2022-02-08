#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
bool isPossible(vector<int> rank, int m, int mid)
{
    int totalDish = 0;
    for (int i = 0; i < rank.size(); i++)
    {
        int time = 0, dish = 1;
        while (time + dish * rank[i] <= mid)
        {
            dish++;
            time = time + dish * rank[i];
        }
        totalDish += dish;
        if (totalDish >= m)
            return true;
    }
    return false;
}
int minCookTime(vector<int> &rank, int m)
{
    int start = 0, end = 0, ans;
    for (int i = 1; i < rank.size(); i++)
        end += rank[i] * i;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(rank, m, mid))
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
    
    return 0;
}