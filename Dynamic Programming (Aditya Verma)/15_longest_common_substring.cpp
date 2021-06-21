// In this problem, you are given two strings and you have to calculate the length of the longest common substring
// not subsequence

#include <bits/stdc++.h>
using namespace std;

int lcs_td(string& s1, string& s2, int m, int n)
{
    int dp[m + 1][n + 1];
    int final = 0;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) // Initialization of base case (represents the state when the length of any of the string is 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1]) // Represents the state when the last character is matching
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else // Represents the state when the last character is not matching
                dp[i][j] = 0;

            final = max(final, dp[i][j]);
        }
    }

    return final;
}

int main()
{
    string s1, s2;
    cout << "Enter the first string : ";
    cin >> s1;
    cout << "Enter the second string : ";
    cin >> s2;
    cout << "Length of the longest common substring : ";
    cout << lcs_td(s1, s2, s1.length(), s2.length()) << "\n";
    return 0;
}