#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int *arr;
    int front, cap, size;
    Queue(int c)
    {
        arr = new int[c];
        cap = c;
        front = 0;
        size = 0;
    }

    bool isFull()
    {
        return cap == size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        else
            return front;
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        else
            return (front + size - 1) % cap;
    }

    void enque(int x)
    {
        if (isFull())
            return;
        int rear = getRear();
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
    }

    void deque()
    {
        if (isEmpty())
            return;
        front = (front + 1) % cap;
        size--;
    }
};

int main()
{
    Queue q(3);
    q.enque(10);
    q.enque(20);
    q.enque(30);
    cout << q.getFront() << " " << q.getRear() << " " << q.size << endl;
    q.deque();
    cout << q.getFront() << " " << q.getRear() << " " << q.size << endl;
    q.deque();
    cout << q.getFront() << " " << q.getRear() << " " << q.size << endl;
    q.enque(40);
    cout << q.getFront() << " " << q.getRear() << " " << q.size << endl;
    q.deque();
    cout << q.getFront() << " " << q.getRear() << " " << q.size << endl;
    return 0;
}