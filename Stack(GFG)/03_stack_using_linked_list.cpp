#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

struct MyStack
{
    Node *head;
    int sz;
    MyStack()
    {
        head = NULL;
        sz = 0;
    }
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        sz++;
    }
    int pop()
    {
        if (head == NULL)
        {
            cout << "Error!!!, Stack is empty";
            return INT_MAX;
        }
        int res = head->data;
        Node *temp = head;
        head = head->next;
        delete (temp);
        sz--;
        return res;
    }
    int size()
    {
        return sz;
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
    int peek()
    {
        if (head == NULL)
        {
            cout << "Error!!!, Stack is empty";
            return INT_MAX;
        }
        return head->data;
    }
};

int main()
{
    MyStack s;
    cout << s.pop() << endl;
    cout << s.peek() << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.peek() << endl;
    s.push(4);
    s.push(5);
    cout << s.pop() << endl;
    cout << s.peek() << endl;
    s.push(6);
    s.push(7);
    return 0;
}