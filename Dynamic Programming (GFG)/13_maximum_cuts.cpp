// Problem : In this problem you are given length of a rod and three values a, b, c and you have to find
// out the maximum no. of pieces in which it can be cut having pieces length as either a, b or c.

#include<bits/stdc++.h>
using namespace std;

int maxCuts(int n, int a, int b, int c)
{

    int dp[n + 1];

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;

        if (i - a >= 0) dp[i] = max(dp[i], dp[i - a]);

        if (i - b >= 0) dp[i] = max(dp[i], dp[i - b]);

        if (i - c >= 0) dp[i] = max(dp[i], dp[i - c]);

        if (dp[i] != -1)
            dp[i]++;
    }

    return dp[n];

}

int main()
{
    int n;
    cout << "Enter the length of the rod : ";
    cin >> n;

    int a, b, c;
    cout << "Enter length of valid pieces (a, b, c) : ";
    cin >> a >> b >> c;

    cout << maxCuts(n, a, b, c) << "\n";
    return 0;
}