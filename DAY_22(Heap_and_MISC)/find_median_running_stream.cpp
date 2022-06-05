#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

class MedianFinder
{
public:
    // We will use maxHeap to store first half and minHeap to store second half
    // 123456
    // 123 -> maxHeap i.e it will give {3}
    // 456 -> minHeap i.e it will give {4}

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.size() == minHeap.size())
        {
            if (maxHeap.size() == 0)
            {
                maxHeap.push(num);
                return;
            }

            if (num < maxHeap.top())
                maxHeap.push(num);
            else
                minHeap.push(num);
        }
        else
        {
            // two cases will be available :
            // 1. maxHeap size will be greater than minHeap
            // 2. minHeap size will be greater than maxheap

            if (minHeap.size() > maxHeap.size())
            {
                if (num <= minHeap.top())
                {
                    maxHeap.push(num);
                }
                else
                {
                    int temp = minHeap.top();
                    minHeap.pop();
                    minHeap.push(num);
                    maxHeap.push(temp);
                }
            }
            else
            {
                if (num >= maxHeap.top())
                    minHeap.push(num);
                else
                {
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);
                    minHeap.push(temp);
                }
            }
        }
    }

    double findMedian()
    {
        if (minHeap.size() == maxHeap.size())
            return (minHeap.top() + maxHeap.top()) / 2.0;
        else if (minHeap.size() > maxHeap.size())
            return minHeap.top();
        else
            return maxHeap.top();
    }
};

// https://leetcode.com/problems/find-median-from-data-stream/

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */