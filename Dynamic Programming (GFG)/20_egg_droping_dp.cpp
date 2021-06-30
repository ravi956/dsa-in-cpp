// Problem : https://leetcode.com/problems/super-egg-drop/

#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(f*f*e)
// Space Complexity => O(f*e)

int eggDrop_rec(int e, int f)
{
    int dp[f + 1][e + 1];

    for (int i = 1; i <= e; i++)
    {
        dp[0][i] = 0;
        dp[1][i] = 1;
    }

    for (int j = 0; j <= f; j++)
        dp[j][1] = j;

    for (int i = 2; i <= f; i++)
    {
        for (int j = 2; j <= e; j++)
        {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= i; x++)
                dp[i][j] = min(dp[i][j], 1 + max(dp[x - 1][j - 1], dp[i - x][j]));
        }
    }
    return dp[f][e];
}

int main()
{
    int e, f;
    cout << "Enter no. of eggs : ";
    cin >> e;
    cout << "Enter no. of floors in building : ";
    cin >> f;

    cout << "Minimum no. of attempts required : " << eggDrop_rec(e, f) << "\n";
    return 0;
}