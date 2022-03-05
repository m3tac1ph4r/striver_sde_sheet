#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

vector<int> nextSmallerElement(vector<int> heights,int n)
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
vector<int> prevSmallerElement(vector<int> heights,int n)
{
    stack<int> myStack;
    vector<int> ans(n);
    for (int i =0;i<n;i++)
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
    int n=heights.size();
    vector<int> next(n);
    next=nextSmallerElement(heights,n);
    vector<int> prev(n);
    prev=prevSmallerElement(heights,n);
    int max_area=INT_MIN;

    for(int i=0;i<n;i++)
    {
        if(next[i]==-1)
            next[i]=n;
        int len=heights[i];
        int bred=next[i]-prev[i]-1;
        max_area=max(max_area,len*bred);
    }
    return max_area;
}
int main()
{
    int n;
    cin>>n;
    vector<int> heights(n);
    for(int i=0;i<n;i++)
        cin>>heights[i];
    cout<<largestRectangleArea(heights);
    return 0;
}

/*

https://leetcode.com/problems/largest-rectangle-in-histogram/

This condition means there is no element smaller than heights[i] 
means we can take size of array as boundary
        if(next[i]==-1)
            next[i]=n;
        
    For example:
    INPUT: {2 1 5 6 2 3}
    NSE: {1 -1 4 4 -1 -1}
    PSE: {-1 -1 1 2 1 4}

    So we if see at index 4 i.e (2) value of NSE at index 4 is -1 means there is no element smaller than
    2. So we will size of array i.e 6 as boundary
*/