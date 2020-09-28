#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Queue
{
    Node *front, *rear;
    int size;

    Queue()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    int getFront()
    {
        if (front == NULL)
            return -1;

        return front->data;
    }

    int getRear()
    {
        if (rear == NULL)
            return -1;

        return rear->data;
    }

    void enque(int x)
    {
        Node *temp = new Node(x);
        size++;
        if (rear == NULL)
        {
            front = temp;
            rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void deque()
    {
        if (front == NULL)
            return;

        Node *temp = front;
        front = front->next;
        size--;
        if (front == NULL)
            rear = NULL;
        delete (temp);
    }
};

int main()
{
    Queue q;
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