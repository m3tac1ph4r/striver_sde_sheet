#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

struct petrolPump
{
    int petrol;
    int distance;
}; 
int tour(petrolPump p[],int n)
{
    int deficit=0;  //kami
    int balance=0;
    int start=0;
    for(int i=0;i<n;i++)
    {
        balance+=p[i].petrol-p[i].distance;
        if(balance<0)
        {
            deficit+=balance;
            start=i+1;
            balance=0;
        }
    }
    if(deficit+balance>=0)
        return start;
    else
        return -1;
}
int main()
{
    int size;
    cin>>size;
    petrolPump p[size];
    for(int i=0;i<size;i++)
    {
        cin>>p[i].petrol>>p[i].distance;
    }
    cout<<tour(p,size);
    return 0;
}

/*
87  27  40  95  71  96  79  35  2    68   3   98  93 
18  57  53  81  2   42  87  90  66   20  45   30  41

69  -30 7   21  90  144 136 81  14  65  23    90   143
*/