#include<bits/stdc++.h>
using namespace std;

// int changeCombination(int coin[], int n, int sum)
// {
//     if (sum == 0)
//         return 1;
//     if (n == 0)
//         return 0;

//     int combinations = 0;

//     combinations += changeCombination(coin, n - 1, sum);
//     if (coin[n - 1] <= sum)
//         combinations += changeCombination(coin, n, sum - coin[n - 1]);

//     return combinations;
// }

int changeCombination(int coin[], int n, int sum)
{
    int dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (coin[i - 1] <= j)
                    dp[i][j] += dp[i][j - coin[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    int n;
    cin >> n;

    int coin[n];
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    int sum;
    cin >> sum;

    cout << changeCombination(coin, n, sum) << endl;
    return 0;
}