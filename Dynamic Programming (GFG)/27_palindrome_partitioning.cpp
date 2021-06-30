#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str, int i, int j)
{
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++, j--;
    }
    return true;
}

// int palindromicPartition(string &str, int i, int j)
// {
//     if (isPalindrome(str, i, j))
//         return 0;

//     int res = INT_MAX;
//     for (int k = i; k < j; k++)
//     {
//         res = min(res, 1 + palindromicPartition(str, i, k) + palindromicPartition(str, k + 1, j));
//     }

//     return res;
// }

int palPart(string &str)
{
    int n = str.length();
    int dp[n][n];

    for (int i = 0; i < n; i++)
        dp[i][i] = 0;

    int col_start = 1;
    while (col_start < n)
    {
        int i = 0, j = col_start;
        while (i < n && j < n)
        {
            if (isPalindrome(str, i, j))
                dp[i][j] = 0;
            else
            {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k + 1][j]);
            }
            i++, j++;
        }
        col_start++;
    }
    return dp[0][n - 1];
}

int main()
{
    string str;
    cin >> str;

    // cout << palindromicPartition(str, 0, str.length() - 1) << "\n";
    cout << palPart(str) << "\n";
    return 0;
}