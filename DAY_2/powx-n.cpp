#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
double myPow(double x,int n)
{
    double ans = 1.0;
    long long i=abs(n);
    while(i>0)
    {
        if(i%2!=0)
        {
            ans=ans*x;
            i=i-1;
        }
        else
        {
            x=x*x;
            i=i/2;
        }
    }
    if(n<0)
        return (1/ans);
    else
        return ans;
}    
int main()
{
    int n;
    double x;
    cin>>x;
    cin>>n;
    cout<<myPow(x,n);
    return 0;
}