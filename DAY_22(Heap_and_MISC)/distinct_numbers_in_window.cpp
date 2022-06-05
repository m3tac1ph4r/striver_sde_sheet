#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

vector<int> distinct_Nums(vector<int> &A, int B)
{
    unordered_map<int, int> mp;
    int i = 0, j = 0;
    vector<int> ans;
    while (j < A.size())
    {
        if (j - i < B)
        {
            mp[A[j]]++;
            j++;
        }
        else
        {
            ans.push_back(mp.size());
            if (mp[A[i]] == 1)
                mp.erase(A[i]);
            else
                mp[A[i]]--;
            mp[A[j]]++;
            i++;
            j++;
        }
    }
    ans.push_back(mp.size());
    return ans;
}

int main()
{
    
    return 0;
}

// https://www.interviewbit.com/problems/distinct-numbers-in-window/