#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    for(int i=0;i<n;i++)
    {
        if (i == 0 || (i > 0 and nums[i] != nums[i - 1]))
        {
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp(3);
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[k];
                    res.push_back(temp);
                    while (j < k and nums[j] == nums[j + 1])
                        j++;
                    while (j < k and nums[k] == nums[k - 1])
                        k--;
                    j++;
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else
                    k--;
            }
        }
    }
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}