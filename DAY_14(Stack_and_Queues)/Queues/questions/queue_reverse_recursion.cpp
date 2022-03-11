#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
void rev(queue<int> &q)
{
    if(q.empty())
        return;
    else
    {
        int num=q.front();
        q.pop();
        rev(q);
        q.push(num);
    }
    
}
void display(queue<int> Q)
{
    while (!Q.empty())
    {
        cout<<Q.front()<<" ";
        Q.pop();
    }
    cout<<"\n";
}
int main()
{
    cout<<"1 for push"<<"\n"
    "2 for display"<<"\n"
    "3 for reverse"<<"\n"
    "4 for stop"<<"\n";
    int n;
    queue<int> q;
    while (true)
    {
        cin>>n;
        switch (n)
        {
        case 1:
            int num;
            cin>>num;
            q.push(num);
            cout<<num<<" pushed in the queue"<<"\n";
            break;
        case 2:
            display(q);
            break;
        case 3:
            rev(q);
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
    
    return 0;
}

/*
https://practice.geeksforgeeks.org/problems/queue-reversal/1
*/