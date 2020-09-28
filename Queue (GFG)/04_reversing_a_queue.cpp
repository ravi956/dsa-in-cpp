#include <bits/stdc++.h>
using namespace std;

void revque(queue<int> &q) //Iterative
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

void reverse(queue<int> &q) //Recursive
{
    if (q.empty())
        return;

    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);
}

int main()
{
    queue<int> q;
    int n;
    cout << "Enter no. of elements in the queue : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        q.push(temp);
    }
    // revque(q);
    reverse(q);
    cout << "Queue after reversing : \n";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}