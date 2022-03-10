#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
class MinStack
{
    stack<long long> myStack;
    long long min_ele;

    public:
    MinStack()
    {
        while (!myStack.empty())
        {
            myStack.pop();
        }
        min_ele = INT_MAX;
    }
    void push(int value)
    {
        long long val = value;
        if (myStack.empty())
        {
            min_ele = val;
            myStack.push(val);
        }
        else if (val < min_ele)
        {
            myStack.push((2 * val) - min_ele);
            min_ele = val;
        }
        else
            myStack.push(val);
    }

    void pop()
    {
        if (myStack.empty())
            return;
        if (myStack.top() < min_ele)
        {
            min_ele = 2 * min_ele - myStack.top();
        }
        myStack.pop();
    }

    int top()
    {
        if (myStack.empty())
            return -1;
        if (myStack.top() < min_ele)
            return min_ele;
        else
            return myStack.top();
    }

    int getMin()
    {
        return min_ele;
    }
};    
int main()
{
    MinStack* obj=new MinStack();
    obj->push(5);
    obj->push(0);
    obj->push(-3);
    cout<<obj->getMin()<<"\n";
    obj->pop();

    obj->push(-1);
    cout << obj->getMin() << "\n";
    cout<<obj->top()<<"\n";
    obj->pop();
    cout << obj->getMin() << "\n";
    return 0;
}

/*
https://leetcode.com/problems/min-stack/
*/

/*
2 * min_ele - myStack.top()
 is used so that we can get the previous min_ele

 Suppose Stack is :
 -3
 0
 5

Current min_ele=-3
push(-4)
push(-4) < min_ele 
{it will store 2*val-min_ele
that is 2*(-4) -(-3) =>-5
So -5 will be push(-5) and min_ele will be equal to -4
Stack: {-5,-3,0,5}
}
Now if pop(){
  if(top()<min_ele)
    it means top of the stack is minimum so we have to update the min_ele to previous
    We will use 2*min_ele - top() => 2*(-4) -(-5) => -3 which is previous min_ele
}

Now Stack is:{-3,0,5}
*/