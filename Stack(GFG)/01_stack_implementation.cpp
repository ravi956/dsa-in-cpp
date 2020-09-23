#include <iostream>
using namespace std;

struct MyStack
{
    int *arr;
    int cap;
    int top;
    MyStack(int c)
    {
        cap = c;
        arr = new int[cap];
        top = -1;
    }
    void push(int x)
    {
        if (top == cap - 1)
        {
            cout << "Stack Overflow Error!!!\n";
            return;
        }
        top++;
        arr[top] = x;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Error, Stack is Empty!!!";
            return 99999999;
        }
        int res = arr[top];
        top--;
        return res;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "Error, Stack is Empty!!!";
            return 99999999;
        }
        return arr[top];
    }
    int size()
    {
        return top + 1;
    }
    bool isEmpty()
    {
        return (top == -1);
    }
};

int main()
{
    MyStack s(5);
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