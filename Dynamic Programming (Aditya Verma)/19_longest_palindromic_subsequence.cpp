// In this problem, you are given a string and you have to give the length of the longest palindromic subsequence
// which means that string which is the longest subsequence of the string and a palindrome too.

// LPS(str) = LCS(str, reverse(str))
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
    string s1;
    cout << "Enter the string : ";
    cin >> s1;
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    cout << "Length of the longest palindromic subsequence : ";
    cout << lcs_bu(s1, s2, s1.length(), s2.length()) << "\n";
    return 0;
}