#include<bits/stdc++.h>
using namespace std;

// Time Complexity => theta(n*n) which can be optimized to O(n*log(n)) and this better solution is based
// on binary search not on dynamic programming
// Space complexity => theta(n)

int LIS(int* arr, int n)
{
    int lis[n];
    lis[0] = 1;

    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }

    int res = *max_element(lis, lis + n);
    return res;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << LIS(arr, n) << '\n';
    return 0;
}