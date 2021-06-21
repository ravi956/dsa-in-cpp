// In this problem, you have to calculate the minimum no. of coins required to make the change

#include <bits/stdc++.h>
using namespace std;

int knapsackTD(int coin[], int sum, int n)
{
    int dp[n + 1][sum + 1];
    //both loops can be combined at one place
    for (int i = 0; i <= n; i++) //For handling base case
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                dp[i][j] = 0;
            if (i == 0)
                dp[i][j] = INT_MAX - 1;
            if (i == 1 && j > 0)
                (j % coin[0] == 0) ? dp[i][j] = j / coin[0] : INT_MAX - 1;
        }

    for (int i = 1; i <= n; i++) //For handling choices
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coin[i - 1] <= j)
                dp[i][j] = min(1 + dp[i][j - coin[i - 1]], dp[i - 1][j]);
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
    int result = knapsackTD(coin, sum, n);
    cout << "Minimum no. of coins required : ";
    (result >= INT_MAX - 1) ? cout << "NOT POSSIBLE" : cout << result;
    return 0;
}