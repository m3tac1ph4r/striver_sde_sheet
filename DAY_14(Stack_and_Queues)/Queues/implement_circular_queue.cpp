#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
class CircularQueue
{
    int* arr;
    int front,rear,size;
    public:
    CircularQueue(int n)
    {
        front=rear=-1;
        size=n;
        arr=new int[size];
    }

    bool enqueue(int value)
    {
        if((front==0 and rear==size-1) or rear==front-1)
        {
            cout<<"Queue is Full"<<"\n";
            return false;
        }
        else
        {
            if(front==-1)
            {
                front=rear=0;
            }
            else if(rear==size-1 and front!=0)
            {
                rear=0;
            }
            else
                rear++;
            arr[rear]=value;
        }
        cout<<value<<" is pushed in queue"<<"\n";
        return true;
    }

    int dequeue()
    {
        if(front==-1)
            return -1;
        int ans=arr[front];
        if(front==rear)
        {
            front=rear=-1;
        }
        else if(front==size-1)
        {
            front=0;
        }
        else
            front++;
        return ans;
    }
};    
int main()
{
    CircularQueue* obj=new CircularQueue(3);
    obj->enqueue(2);
    obj->enqueue(3);
    cout<<obj->dequeue()<<"\n";
    obj->enqueue(4);
    obj->enqueue(6);
    obj->enqueue(7);
    cout<<obj->dequeue()<<"\n";
    return 0;
}

/*
https://www.codingninjas.com/codestudio/problems/circular-queue_1170058
*/