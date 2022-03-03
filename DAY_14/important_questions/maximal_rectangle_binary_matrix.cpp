#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

vector<int> nextSmallerElement(vector<int> heights, int n)
{
    stack<int> myStack;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (myStack.empty())
        {
            ans[i] = -1;
            myStack.push(i);
        }
        else
        {
            if (heights[myStack.top()] < heights[i])
                ans[i] = myStack.top();
            else if (heights[myStack.top()] >= heights[i])
            {
                while (myStack.empty() == false and heights[myStack.top()] >= heights[i])
                {
                    myStack.pop();
                }
                if (myStack.empty())
                    ans[i] = -1;
                else if (heights[myStack.top()] < heights[i])
                    ans[i] = myStack.top();
            }
            myStack.push(i);
        }
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> heights, int n)
{
    stack<int> myStack;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (myStack.empty())
        {
            ans[i] = -1;
            myStack.push(i);
        }
        else
        {
            if (heights[myStack.top()] < heights[i])
                ans[i] = myStack.top();
            else if (heights[myStack.top()] >= heights[i])
            {
                while (myStack.empty() == false and heights[myStack.top()] >= heights[i])
                {
                    myStack.pop();
                }
                if (myStack.empty())
                    ans[i] = -1;
                else if (heights[myStack.top()] < heights[i])
                    ans[i] = myStack.top();
            }
            myStack.push(i);
        }
    }
    return ans;
}
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> next(n);
    next = nextSmallerElement(heights, n);
    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);
    int max_area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (next[i] == -1)
            next[i] = n;
        int len = heights[i];
        int bred = next[i] - prev[i] - 1;
        max_area = max(max_area, len * bred);
    }
    return max_area;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int max_area=INT_MIN;
    int n = matrix.size();
    int m=matrix[0].size();
    vector<int> sumMatrix(m, 0);
    for (int i = 0; i <n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
                sumMatrix[j] += 1;
            else
                sumMatrix[j]=0;
        }
        int area=largestRectangleArea(sumMatrix);
        // for(int k=0;k<m;k++)
        //     cout<<sumMatrix[k]<<" ";
        // cout<<"\n";
        max_area=max(area,max_area);
    }
    return max_area;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> matrix(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>matrix[i][j];
    }
    cout<<maximalRectangle(matrix);
    return 0;
}

