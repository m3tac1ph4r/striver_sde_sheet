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
    int deficit=0;  //kami petrol ki
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
https://practice.geeksforgeeks.org/problems/circular-tour/1#
https://leetcode.com/problems/gas-station/
*/