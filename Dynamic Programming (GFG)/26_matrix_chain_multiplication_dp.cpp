#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(n*n*n)
// Space Complexity => O(n*n)

int mcm_dp(int* arr, int n)
{
    int dp[n][n];

    for (int i = 0; i < n - 1; i++)
        dp[i][i + 1] = 0;

    int col_start = 2;
    while (col_start < n)
    {
        int i = 0, j = col_start;
        while (i < n && j < n)
        {
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j]);

            i++, j++;
        }
        col_start++;
    }
    return dp[0][n - 1];
}

int main()
{
    int n;
    cin >> n;

    // n inputs represent n-1 matrices
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << mcm_dp(arr, n) << "\n";
    return 0;
}