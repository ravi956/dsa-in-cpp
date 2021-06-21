// Problem : https://leetcode.com/problems/super-egg-drop/

#include<bits/stdc++.h>
using namespace std;

int dp[11][51];

int eggDrop_mem(int e, int f)
{
    if (f == 0 || f == 1)
        return f;

    if (e == 1)
        return f;

    if (dp[e][f] != -1)
        return dp[e][f];

    int min_attempt = INT_MAX;

    for (int k = 1; k <= f; k++)
    {
        int temp = 1 + max(eggDrop_mem(e - 1, k - 1), eggDrop_mem(e, f - k));
        if (temp < min_attempt)
            min_attempt = temp;
    }

    return dp[e][f] = min_attempt;
}

int main()
{
    int e, f;
    cout << "Enter no. of eggs : ";
    cin >> e;
    cout << "Enter no. of floors in building : ";
    cin >> f;

    memset(dp, -1, sizeof(dp));
    cout << "Minimum no. of attempts required : " << eggDrop_mem(e, f) << "\n";
    return 0;
}