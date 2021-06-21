#include <bits/stdc++.h>
using namespace std;

int dp[102][1002]; //size depends on constraints, rows->n, col->W

int knapsackMem(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (wt[n - 1] <= W)
    {
        return dp[n][W] = max(val[n - 1] + knapsackMem(wt, val, W - wt[n - 1], n - 1),
                              knapsackMem(wt, val, W, n - 1));
    }
    else
    {
        return dp[n][W] = knapsackMem(wt, val, W, n - 1);
    }
}

int main()
{
    int n, W;
    memset(dp, -1, sizeof(dp));
    cout << "Enter no. of item (n) : ";
    cin >> n;
    int val[n], wt[n];
    cout << "Enter values of the items :\n";
    for (int i = 0; i < n; i++)
        cin >> val[i];
    cout << "Enter weights of the items :\n";
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    cout << "Enter capacity of the knapsack : ";
    cin >> W;
    cout << "Maximum Profit : ";
    cout << knapsackMem(wt, val, W, n);
    return 0;
}