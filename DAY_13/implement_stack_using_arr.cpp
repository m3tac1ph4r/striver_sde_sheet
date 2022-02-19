#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

class MyStack
{
    private:
        int arr[100];
        int top;
    public:
        MyStack()
        {
            top=-1;
        }
        int pop()
        {
            if(top<0)
                return -1;
            else
            {
                int temp=arr[top];
                top--;
                return temp;
            }
        }
        void push(int x)
        {
            arr[top++]=x;
        }
};
int main()
{
    MyStack *obj=new MyStack();
    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int x;
            cin>>x;
            obj->push(x);
        }
        else if(type==2)
        {
            cout<<obj->pop()<<" ";
        }
    }
    
    return 0;
}
