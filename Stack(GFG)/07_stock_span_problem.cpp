#include <bits/stdc++.h>
using namespace std;

void printSpan(int arr[], int n)
{
    stack<int> s;
    s.push(0);
    cout << 1 << " ";
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] <= arr[i])
            s.pop();

        int span = s.empty() ? i + 1 : i - s.top();
        cout << span << " ";
        s.push(i);
    }
}

int main()
{
    int n;
    cout << "Enter the no. of entries of stocks : ";
    cin >> n;
    int arr[n];
    cout << "Enter stock values :\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Stock Spans :\n";
    printSpan(arr, n);
    return 0;
}