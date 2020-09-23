#include <iostream>
#include <vector>
using namespace std;

struct MyStack
{
    vector<int> v;
    void push(int x)
    {
        v.push_back(x);
    }
    int pop()
    {
        if (v.size() == 0)
        {
            cout << "Error, Stack is Empty!!!";
            return 99999999;
        }
        int res = v.back();
        v.pop_back();
        return res;
    }
    int size()
    {
        return v.size();
    }
    bool isEmpty()
    {
        return v.empty();
    }
    int peek()
    {
        if (v.size() == 0)
        {
            cout << "Error, Stack is Empty!!!";
            return 99999999;
        }
        return v.back();
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