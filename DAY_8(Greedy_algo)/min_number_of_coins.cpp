#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

int minCoins(int coins[],int M,int V)
{
    int ans = 0;
    sort(coins, coins + M);
    for (int i = M - 1; i >= 0; i--)
    {
        while (V >= coins[i])
        {
            V -= coins[i];
            ans++;
        }
    }
    return ans;
}
int main()
{
    int V,m;
    cin>>V;
    cin>>m;
    int coins[m];
    for (int i = 0; i < m; i++)
        cin>>coins[i];
    cout<<minCoins(coins,m,V);
    return 0;
}