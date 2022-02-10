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
    int start = 0, end = 1e4, ans;
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
    int n,m;
    cin>>n>>m;
    vector<int> rank(n);
    for(int i=0;i<n;i++)
        cin>>rank[i];
    cout<<minCookTime(rank,m);
    return 0;
}

/*
https://www.codingninjas.com/codestudio/problems/cooking-ninjas_1164174

Another same problem: https://www.spoj.com/problems/PRATA/
*/