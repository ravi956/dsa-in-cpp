#include<bits/stdc++.h>
using namespace std;

// int count_bst(int n)
// {
//     if (n == 0)
//         return 1;

//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         count += count_bst(i) * count_bst(n - i - 1);
//     }

//     return count;
// }

// Time complexity => O(n*n)
// Space complexity => O(n)

int count_bst(int n)
{
    int dp[n + 1];
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
        {
            dp[i] += (dp[j] * dp[i - 1 - j]);
        }
    }
    return dp[n];
}

// It can also be calculated in theta(n) time and theta(1) auxiliary space as the result for n is
// actually nth CATALAN NUMBER which is given by formula :
// res(n) = (1/(n+1))*((2n)C(n))
// where C stands for combination

int main()
{
    int n;
    cin >> n;

    cout << count_bst(n) << "\n";
    return 0;
}