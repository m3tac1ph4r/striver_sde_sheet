#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    bool result=false;
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[i][j]==target)
                result=true;
            else
                continue;
        }
    }
    return result;
}
int main()
{
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=3;
    if(searchMatrix(matrix,target))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}