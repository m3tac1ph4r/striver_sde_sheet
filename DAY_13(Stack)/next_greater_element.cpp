#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

vector<int> nextGreater(vector<int> &arr, int n)
{
    stack<int> myStack;
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--)
    {
        if(myStack.empty())
        {
            ans[i]=-1;
            myStack.push(arr[i]);
        
        }
        else
        {
            if(myStack.top()>arr[i])
            {
                ans[i]=myStack.top();
            }
            else if(myStack.top()<=arr[i])
            {
                while(myStack.empty()==false and myStack.top()<=arr[i])
                {
                    myStack.pop();
                }
                if(myStack.empty() or myStack.top()==arr[i])
                {
                    ans[i]=-1;
                }
                else if(myStack.top()>arr[i])
                    ans[i]=myStack.top();
            }
            myStack.push(arr[i]);
        }
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        vector<int> ans=nextGreater(arr,n);
        // f    or(int i=0;i<n;i++)
        //     cout<<arr[i]<<" "<<ans[i]<<"\n";
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}

/*
VERY IMPORTANT QUESTION
/*
https://www.codingninjas.com/codestudio/problems/799354
*/

/* BRUTEFORCE APPROACH
vector<int> nextGreater(vector<int> &arr, int n)
{
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++)
    {
        bool flag=false;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i])
            {
                ans[i]=arr[j];
                flag=true;
                break;
            }
        }
        if(flag==false)
            ans[i]=-1;
    }
    return ans;
}

*/