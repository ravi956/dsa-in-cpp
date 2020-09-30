#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev, *next;
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

struct Deque
{
    Node *front, *rear;
    int size;

    Deque()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void deleteFront()
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

    void insertRear(int x)
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
        temp->prev = rear;
        rear = temp;
    }

    int getFront()
    {
        if (front == NULL)
            return -1;

        return front->data;
    }

    void insertFront(int x)
    {
        Node *temp = new Node(x);
        size++;
        if (front == NULL)
        {
            front = temp;
            rear = temp;
            return;
        }
        temp->next = front;
        front->prev = temp;
        front = temp;
    }

    void deleteRear()
    {
        if (front == NULL)
            return;

        Node *temp = rear;
        rear = rear->prev;
        size--;
        if (rear == NULL)
            front = NULL;
        delete (temp);
    }

    int getRear()
    {
        if (rear == NULL)
            return -1;

        return rear->data;
    }
};

int main()
{
    Deque dq;
    dq.insertFront(10);
    cout << dq.getFront() << " " << dq.getRear() << " " << dq.size << endl;
    dq.insertRear(20);
    cout << dq.getFront() << " " << dq.getRear() << " " << dq.size << endl;
    dq.insertRear(30);
    cout << dq.getFront() << " " << dq.getRear() << " " << dq.size << endl;
    dq.deleteFront();
    cout << dq.getFront() << " " << dq.getRear() << " " << dq.size << endl;
    dq.deleteRear();
    cout << dq.getFront() << " " << dq.getRear() << " " << dq.size << endl;
    return 0;
}