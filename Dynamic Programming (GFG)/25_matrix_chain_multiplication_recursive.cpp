#include<bits/stdc++.h>
using namespace std;

int mcm_rec(int* arr, int i, int j)
{
    if (i + 1 == j)
        return 0;

    int res = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        res = min(res, mcm_rec(arr, i, k) + mcm_rec(arr, k, j) + arr[i] * arr[k] * arr[j]);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    // n inputs represent n-1 matrices
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << mcm_rec(arr, 0, n - 1) << "\n";
    return 0;
}