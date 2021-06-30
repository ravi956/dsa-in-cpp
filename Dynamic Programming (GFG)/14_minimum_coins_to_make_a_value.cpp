// Problem : You are given coin denominations with infinite no. of supply , you have to find the minimum
// no. of coins required to make a value.

#include<bits/stdc++.h>
using namespace std;

// int minCoinsRec(int* coins, int n, int sum)
// {
//     if (sum == 0)
//         return 0;

//     int res = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         if (sum >= coins[i])
//         {
//             int sub_res = minCoinsRec(coins, n, sum - coins[i]);
//             if (sub_res != INT_MAX)
//                 res = min(res, sub_res + 1);
//         }
//     }

//     return res;
// }

// Time Complexity => O(n * sum)
// Space Complexity => theta(sum)

int minCoins(int* coins, int n, int sum)
{
    vector<int> dp(sum + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= sum; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }
    return dp[sum];
}

int main()
{
    int n;
    cout << "Enter no. of coins : ";
    cin >> n;

    int coins[n];
    cout << "Enter coin denominations :\n";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int sum;
    cout << "Enter the value or sum : ";
    cin >> sum;

    // cout << minCoinsRec(coins, n, sum) << '\n';
    cout << minCoins(coins, n, sum) << "\n";
    return 0;
}