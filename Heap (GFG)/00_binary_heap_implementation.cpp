#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    int *arr;
    int size;
    int capacity;

public:
    MinHeap(int c)
    {
        size = 0;
        capacity = c;
        arr = new int[c];
    };

    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int parent(int i) { return (i - 1) / 2; }

    void insert(int x);
    void minHeapify(int i);
    int extractMin();
    void decreaseKey(int i, int x);
    void deleteKey(int i);
    void buildHeap();
};

// Time Complexity = O(log(size))
// Space Complexity = O(1)
void MinHeap ::insert(int x)
{
    if (size == capacity)
        return;
    size++;
    arr[size - 1] = x;
    for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i];)
    {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

// Time Complexity = O(log(n))
// Space Complexity = O(log(n)) for recursive , it can be easily
// changed to iterative and then space complexity wil be O(1)
void MinHeap ::minHeapify(int i)
{
    int lt = left(i), rt = right(i);
    int smallest = i;
    if (lt < size && arr[lt] < arr[i])
        smallest = lt;
    if (rt < size && arr[rt] < arr[smallest])
        smallest = rt;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(smallest);
    }
}

// Time Complexity = O(log(n))
// Space Complexity = Depends on minHeapify() => O(log(n)) or O(1)
int MinHeap ::extractMin()
{
    if (size == 0)
        return INT_MAX;

    if (size == 1)
    {
        size--;
        return arr[0];
    }

    swap(arr[0], arr[size - 1]);
    size--;
    minHeapify(0);
    return arr[size];
}

// Time Complexity = O(log(n))
// Space Complexity = O(1)
void MinHeap ::decreaseKey(int i, int x)
{
    arr[i] = x;
    while (i != 0 && arr[parent(i)] > arr[i])
    {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

// Time Complexity = O(log(n))
// Space Complexity => Depends on recursive or iterative of minHeapify()
void MinHeap ::deleteKey(int i)
{
    if (i >= size)
        return;
    decreaseKey(i, INT_MIN);
    extractMin();
}

// Time Complexity = O(n)
void MinHeap ::buildHeap()
{
    for (int i = (size - 2) / 2; i >= 0; i--)
        minHeapify(i);
}
int main()
{
    MinHeap h(11);
    return 0;
}