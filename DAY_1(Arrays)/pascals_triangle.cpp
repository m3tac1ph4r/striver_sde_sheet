#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    ans.push_back({1});
    if (numRows == 1)
        return ans;
    ans.push_back({1, 1});
    if (numRows == 2)
        return ans;
    ans.push_back({1, 2, 1});
    vector<int> temp = {1, 2, 1};
    vector<int> temp2;
    for (int j = 3; j < numRows; j++)
    {
        temp2.push_back(temp[0]);
        for (int i = 1; i < temp.size(); i++)
        {
            temp2.push_back(temp[i - 1] + temp[i]);
        }
        temp2.push_back(temp[temp.size() - 1]);
        ans.push_back(temp2);
        temp = temp2;
        temp2 = {};
    }
    return ans;
}
int main()
{
    int numRows;
    cin>>numRows;
    vector<vector<int>> ans=generate(numRows);
    for(auto &i:ans)
    {
        for(auto &j:i)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}