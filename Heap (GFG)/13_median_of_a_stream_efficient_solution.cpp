#include <bits/stdc++.h>
using namespace std;

// Time Complexity => O(n*log(n))
// Advantage over better solution is : It uses Heap (which is cache freindly) instead of Augmented BST
void printMedians(int arr[], int n)
{
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<>> g;

    s.push(arr[0]);
    cout << arr[0] << " ";

    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        if (s.size() > g.size())
        {
            if (s.top() > x)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);
            cout << (s.top() + g.top()) / 2.0 << " ";
        }
        else
        {
            if (x <= s.top())
                s.push(x);
            else
            {
                g.push(x);
                s.push(g.top());
                g.pop();
            }
            cout << s.top() << " ";
        }
    }
}

int main()
{
    int keys[] = {25, 7, 10, 15, 20};
    printMedians(keys, 5);
    return 0;
}