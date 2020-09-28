#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    queue<int> q1;
    queue<int> q2;

    int top()
    {
        if (q1.empty())
            return -1;

        return q1.front();
    }

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            int temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        swap(q1, q2);
    }

    int pop()
    {
        int temp = q1.front();
        q1.pop();
        return temp;
    }

    int size()
    {
        return q1.size();
    }
};

int main()
{
    Stack st;
    st.push(10);
    cout << st.top() << " " << st.size() << endl;
    st.push(20);
    cout << st.top() << " " << st.size() << endl;
    st.push(30);
    cout << st.top() << " " << st.size() << endl;
    cout << st.pop() << endl;
    st.push(40);
    cout << st.top() << " " << st.size() << endl;
    return 0;
}