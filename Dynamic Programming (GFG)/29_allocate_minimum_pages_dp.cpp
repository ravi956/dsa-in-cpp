#include<bits/stdc++.h>
using namespace std;

int sum(int *arr, int b, int e)
{
    int total = 0;
    for (int i = b; i <= e; i++)
        total += arr[i];

    return total;
}

// Time Complexity => O(n*n*n*k) , Space Complexity => theta(n*k)
// time complexity can be reduced to O(n*n*k) by doing precomputation to store sums in a 2d matrix then space complexity => O(n*n)
// There is a better algorithm to solve this problem , Binary Search can solve this problem in O(n*logn*sum)
// but if sum is very large then it is not better as compared to dp solution where sum is the sum of all pages in the book

int minPages(int *arr, int n, int k)
{
    int dp[k + 1][n + 1];

    for (int i = 2; i <= n; i++)
        dp[1][i] = sum(arr, 0, i - 1);

    for (int i = 2; i <= k; i++)
        dp[i][1] = arr[0];

    for (int i = 2; i <= k; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            int res = INT_MAX;
            for (int p = 1; p < j; p++)
            {
                res = min(res, max(dp[i - 1][p], sum(arr, p, j - 1)));
            }
            dp[i][j] = res;
        }
    }
    return dp[k][n];
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    cout << minPages(arr, n, k) << "\n";
    return 0;
}