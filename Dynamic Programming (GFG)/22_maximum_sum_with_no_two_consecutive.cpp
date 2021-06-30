// Problem : In this problem, you are given an array you have to find the sum of a sequence of the array
// which is maximum and the elements in the sequence are not consecutive.

#include<bits/stdc++.h>
using namespace std;

// int maxSum(int* arr, int n)
// {
//     if (n <= 0)
//         return 0;

//     return max(arr[n - 1] + maxSum(arr, n - 2), maxSum(arr, n - 1));
// }

// Time Complexity => theta(n), Space Complexity => theta(n)
int maxSum(int* arr, int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = arr[0];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], arr[i - 1] + dp[i - 2]);
    }
    return dp[n];
}

// Time Complexity => theta(n), Space Complexity => theta(1)
int maxSumOptimized(int* arr, int n)
{
    if (n == 1) return arr[0];
    int prev_prev, prev, res;
    prev_prev = arr[0];
    prev = max(arr[0], arr[1]);
    res = prev;
    for (int i = 3; i <= n; i++)
    {
        res = max(prev, prev_prev + arr[i - 1]);
        prev_prev = prev;
        prev = res;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxSum(arr, n) << "\n";
    cout << maxSumOptimized(arr, n) << "\n";
    return 0;
}