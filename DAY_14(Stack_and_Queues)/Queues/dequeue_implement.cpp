#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
class Deque
{
    int *arr;
    int size,front,rear;
    public:
    // Initialize your data structure.
    Deque(int n)
    {
        size=n;
        arr=new int[n];
        front=rear=-1;
    }
    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if ((front == 0 and rear == size - 1) or (front != 0 and rear == front - 1))
            return true;
        else
            return false;
    }
    bool pushFront(int x)
    {
        if (isFull())
            return false;
        else
        {
            if (isEmpty())
            {
                front = rear = 0;
            }
            else if (front == 0 and rear != size - 1)
                front = size - 1;
            else
                front--;
            arr[front] = x;
        }
        return true;
    }
    bool pushRear(int x)
    {
        if (isFull())
        {
            return false;
        }
        else
        {
            if (isEmpty())
            {
                front = rear = 0;
            }
            else if (rear == size - 1 and front != 0)
            {
                rear = 0;
            }
            else
                rear++;
            arr[rear] = x;
        }
        return true;
    }
    int popFront()
    {
        if (isEmpty())
            return -1;
        int ans = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
            front++;
        return ans;
    }
    int popRear()
    {
        if (isEmpty())
            return -1;
        int ans = arr[rear];
        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = size - 1;
        else
            rear--;
        return ans;
    }
    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }
};    
int main()
{
    
    return 0;
}