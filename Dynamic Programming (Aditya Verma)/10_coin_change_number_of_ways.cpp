// In this problem, you have to find out the no. of ways to do the coin change

#include <bits/stdc++.h>
using namespace std;

int knapsackBU(int coin[], int sum, int n)
{
    int dp[n + 1][sum + 1];
    //both loops can be combined at one place
    for (int i = 0; i <= n; i++) //For handling base case
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }

    for (int i = 1; i <= n; i++) //For handling choices
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coin[i - 1] <= j)
                dp[i][j] = dp[i][j - coin[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int n, sum;
    cout << "Enter no. of coins (n) : ";
    cin >> n;
    int coin[n];
    cout << "Enter values of the coins :\n";
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    cout << "Enter sum : ";
    cin >> sum;
    cout << "Total no. of ways : ";
    cout << knapsackBU(coin, sum, n);
    return 0;
}