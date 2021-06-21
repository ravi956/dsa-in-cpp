#include<bits/stdc++.h>
using namespace std;

int dp[10000][10000];

int mcm_mem(int* arr, int i, int j)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        ans = min(ans, mcm_mem(arr, i, k) + mcm_mem(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j]);
    }
    return dp[i][j] = ans;
}

int main()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));
    int arr[n]; // Dimension of the ith matrix is arr[i-1]xarr[i]
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = mcm_mem(arr, 1, n - 1);
    cout << ans << "\n";
    return 0;
}