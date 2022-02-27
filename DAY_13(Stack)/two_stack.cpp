#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
class TwoStack
{
    int *arr;
    int top1,top2,size;
    TwoStack(int s)
    {
        this->size=s;
        top1=-1;
        top2=s;
        arr=new int[s];
    };
    // Push in stack 1.
    void push1(int num)
    {
        // Write your code here.
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        // Write your code here.
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        // Write your code here.
        int ans;
        if (top1 == -1)
        {
            ans = -1;
        }
        else
        {
            ans = arr[top1--];
        }
        return ans;
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        // Write your code here.
        int ans;
        if (top2 == size)
        {
            ans = -1;
        }
        else
        {
            ans = arr[top2++];
        }
        return ans;
    }
};    
int main()
{
    
    return 0;
}


/*
https://www.codingninjas.com/codestudio/problems/two-stacks_983634?leftPanelTab=0
*/
