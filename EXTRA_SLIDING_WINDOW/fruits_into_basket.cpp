#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0,right=0,n=fruits.size();
        int distinct=0;
        unordered_map<int,int> mp;
        int ans=0;
        while(left<=right and right<n)
        {
            // fruits[right] is a new fruit so we have to delete
            if(mp.find(fruits[right])==mp.end() and distinct>=2)
            {
                
                while(left<right and distinct>=2)
                {
                    mp[fruits[left]]--;
                    if(mp[fruits[left]]==0)
                    {
                        mp.erase(fruits[left]);
                        distinct--;
                    }
                    left++;
                }
            }
            else if(mp.find(fruits[right])==mp.end() and distinct<2)
            {
                mp[fruits[right]]++;
                distinct++;
                ans=max(ans,right-left+1);
                right++;
            }
            else
            {
                mp[fruits[right]]++;
                ans=max(ans,right-left+1);
                right++;
            }
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}

// https://leetcode.com/problems/longest-substring-without-repeating-characters/