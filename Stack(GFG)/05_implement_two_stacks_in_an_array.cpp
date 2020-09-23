#include <bits/stdc++.h>
using namespace std;

struct TwoStacks
{
    int *arr, cap, top1, top2;
    TwoStacks(int n)
    {
        cap = n;
        top1 = -1;
        top2 = cap;
        arr = new int[n];
    }
    void push1(int x)
    {
        if (top1 == top2 - 1)
        {
            cout << "Error!!!, Overflow";
            return;
        }
        top1++;
        arr[top1] = x;
    }
    void push2(int x)
    {
        if (top1 == top2 - 1)
        {
            cout << "Error!!!, Overflow";
            return;
        }
        top2--;
        arr[top2] = x;
    }
    int pop1()
    {
        if (top1 == -1)
        {
            cout << "Error!!!, Stack1 is empty";
            return INT_MAX;
        }
        int res = arr[top1];
        top1--;
        return res;
    }
    int pop2()
    {
        if (top2 == cap)
        {
            cout << "Error!!!, Stack2 is empty";
            return INT_MAX;
        }
        int res = arr[top2];
        top2++;
        return res;
    }
    int size1()
    {
        return top1 + 1;
    }
    int size2()
    {
        return cap - top2;
    }
    //Similarly you can write function for finding the top elements of the two stacks
};

int main()
{
    TwoStacks s(6);
    s.push1(10);
    s.push1(20);
    s.push2(30);
    s.push2(40);
    cout << s.pop1() << endl;
    cout << s.pop2() << endl;
    s.push2(50);
    s.push2(60);
    cout << "size1 = " << s.size1() << " size2 = " << s.size2() << endl;
    s.push1(70);
    cout << "size1 = " << s.size1() << " size2 = " << s.size2() << endl;
    s.push1(80);
    cout << "size1 = " << s.size1() << " size2 = " << s.size2() << endl;
    s.push1(90);
    return 0;
}