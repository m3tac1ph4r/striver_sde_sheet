#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
class Queue
{
    int* arr;
    int front,rear,size;
    public:
        Queue(int s)
        {
            size=s;
            arr=new int[size];
            front=-1;
            rear=-1;
        }
        bool isEmpty()
        {
            if(front==rear)
                return false;
            else
            {
                return true;
            }
        }
        void enqueue(int data)
        {
            if(rear==size)
                cout<<"Queue is full";
            else
            {
                if(front==-1 or rear==-1)
                {
                    front=0;
                    rear=0;
                    arr[rear]=data;
                    rear++;
                }
                else
                {
                    arr[rear]=data;
                    rear++;
                }
            }
        }
        int dequeue()
        {
            int ans;
            if(front==rear)
                return -1;
            else
            {
                ans=arr[front];
                front++;
                if(front==rear)
                {
                    front=0;
                    rear=0;
                }
            }
            return ans;
        }
        int qfront()
        {
            if(front==rear)
                return -1;
            return arr[front];
        }
};    
int main()
{
    int size=5;
    Queue* obj=new Queue(size);
    obj->enqueue(1);
    cout<<"front "<<obj->qfront()<<"\n";
    obj->enqueue(5);
    obj->enqueue(6);
    obj->enqueue(7);
    cout<<"Dequeue "<<obj->dequeue()<<"\n";
    cout << "Dequeue " << obj->dequeue() << "\n";
    cout << "front " << obj->qfront() << "\n";
    return 0;
}

/*
https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908
*/