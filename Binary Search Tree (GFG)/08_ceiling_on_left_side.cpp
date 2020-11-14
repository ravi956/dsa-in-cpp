#include <bits/stdc++.h>
using namespace std;

// Time Complexity => O(nlogn)
// Space Complexity => O(n)
void printCeiling(int arr[], int n)
{
    set<int> s;

    cout << -1 << " ";
    s.insert(arr[0]);

    for (int i = 1; i < n; i++)
    {
        auto it = s.lower_bound(arr[i]);
        if (it != s.end())
            cout << *it << " ";
        else
            cout << -1 << " ";

        s.insert(arr[i]);
    }
}

int main()
{
    int n;
    cout << "Enter no. of elements in array : ";
    cin >> n;

    int arr[n];
    cout << "Enter elements :\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    printCeiling(arr, n);
    return 0;
}