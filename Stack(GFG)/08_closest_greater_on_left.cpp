#include <bits/stdc++.h>
using namespace std;

void printClosestGreaterElement(int arr[], int n)
{
    stack<int> s;
    cout << -1 << " ";
    s.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && s.top() <= arr[i])
            s.pop();

        int closestGreater = s.empty() ? -1 : s.top();
        cout << closestGreater << " ";
        s.push(arr[i]);
    }
}

int main()
{
    int n;
    cout << "Enter no. of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements :\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Closest greater element on left :\n";
    printClosestGreaterElement(arr, n);
    return 0;
}