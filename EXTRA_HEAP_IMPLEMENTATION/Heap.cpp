#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

class heap
{
public:
    int arr[100];
    int size = 0;
    /*
    left child -> 2*i+1
    right child -> 2*i+2
    parent -> i/2
    */

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void insert(int val)
    {
        size += 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }
    // time complexity og insertion is O(logn)

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing in the Heap" << endl;
            return;
        }

        arr[1] = arr[size]; // replace the last index with root node i.e 1st
        size--;

        // take root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            if (leftIndex < size and arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size and arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
    // time complexity of deletion is O(logn)

    // heapify is used to find the correct position of that element
    void heapify(int arr[], int i, int n)
    {
        int largest = i;
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;

        if (leftIndex < n and arr[largest] < arr[leftIndex])
            largest = leftIndex;
        if (rightIndex < n and arr[largest] < arr[rightIndex])
            largest = rightIndex;

        if (i != largest)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, largest, n);
        }
    }

    // heapifyMain will sort the array in maxHeap
    // Time Complexity : O(n)
    void heapifyMain(int arr[], int n)
    {
        // we will not traverse for the leave nodes because they are already in heap
        // So leaves will be from (n/2 +1) to n

        for (int i = n / 2; i >= 0; i--)
            heapify(arr, i, n);

        // https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167?leftPanelTab=0
    }
};
int main()
{

    return 0;
}