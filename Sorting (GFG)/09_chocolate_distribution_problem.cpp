#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int m)
{
    sort(arr, arr + n);
    int minimum = INT_MAX;
    for (int i = 0; i + m - 1 < n; i++)
    {
        minimum = min(minimum, arr[i + m - 1] - arr[i]);
    }
    return minimum;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << solve(arr, n, m);
    return 0;
}
