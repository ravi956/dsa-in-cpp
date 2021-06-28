// In this problem we have to find out the given a pattern string is a subequence of the another string or not

#include <bits/stdc++.h>
using namespace std;

int lcs_bu(string& s1, string& s2, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) // Initialization of base case (represents the state when the length of any of the string is 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1]) // Represents the state when the last character is matching
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else // Represents the state when the last character is not matching
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main()
{
    string s1, s2;
    cout << "Enter the string (in which pattern is to be searched): ";
    cin >> s1;
    cout << "Enter the string (pattern to be searched) : ";
    cin >> s2;
    int lcs_length = lcs_bu(s1, s2, s1.length(), s2.length());
    if (lcs_length == s2.length())
        cout << "TRUE\n";
    else
        cout << "FALSE\n";
    return 0;
}