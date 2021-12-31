#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

void merge(vector<int> num1,int m,vector<int> num2,int n)
{
    int l = 0;
    for (int k = m; k < m + n; k++)
    {
        num1[k] = num2[l++];
    }
    sort(num1.begin(), num1.end());
    for (int t = 0; t < m + n; t++)
        cout << num1[t] << " ";
}    
int main()
{
    vector<int> num1={1,2,3,0,0,0};
    int m=3,n=3;
    vector<int> num2={2,5,6};
    merge(num1,m,num2,n);
    return 0;
}

/*
QUESTION LINK : https://leetcode.com/problems/merge-sorted-array/
*/