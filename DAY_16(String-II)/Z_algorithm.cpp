#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

int zAlgorithm(string s,string p,int n,int m)
{
    string new_s=p+'$'+s;
    int new_len=new_s.length();
    int Z[new_len];
    Z[0] = 0;
    int left = 0, right = 0;
    for (int k = 1; k < new_len; k++)
    {
        if (k > right)
        {
            left = k;
            right = k;
            while (right < new_len and new_s[right] == new_s[right - left])
            {
                right++;
            }
            Z[k] = right - left;
            right--;
        }
        else
        {
            // we are operating inside box
            int k1 = k - left;
            // if value does not stretches till right bound then just copy it.
            if (Z[k1] < right - k + 1)
            {
                Z[k] = Z[k1];
            }
            else
            {
                // otherwise try to see if there are more matches.
                left = k;
                while (right < new_len and new_s[right] == new_s[right - left])
                {
                    right++;
                }
                Z[k] = right - left;
                right--;
            }
        }
    }
    int count=0;
    for(int i=0;i<new_len;i++)
    {
        if(Z[i]==p.length())
            count++;
    }
    return count;
}    
int main()
{
    string s,p;
    cin>>s;
    cin>>p;
    cout<<zAlgorithm(s,p,s.length(),p.length());
    return 0;
}

/*
Best website to determine how to find Z array:
https://personal.utdallas.edu/~besp/demo/John2010/z-algorithm.htm

https://youtu.be/CpZh4eF8QBw
*/
/*
https://www.codingninjas.com/codestudio/problems/1112619
*/

/*
Worst Case Time complexity: O(m+n)
*/