// In Unbound Knapsack problem, there is infinite quantity of every instance / item is available to be chosen
// in the knapsack but there is still some capacity of the knapsack

// Rod Cutter problem is same as unbounded knapsack;
// Treat values as costs at 0th index -> store cost for length 1
// Consider weights as lengths
// Consider capacity W as length of the given rod

#include <bits/stdc++.h>
using namespace std;

int knapsackBU(int wt[], int val[], int W, int n)
{
    int dp[n + 1][W + 1];
    //both loops can be combined at one place
    for (int i = 0; i <= n; i++) //For handling base case
        for (int j = 0; j <= W; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    for (int i = 1; i <= n; i++) //For handling choices
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}

int main()
{
    int n, W;
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
    cout << knapsackBU(wt, val, W, n);
    return 0;
}