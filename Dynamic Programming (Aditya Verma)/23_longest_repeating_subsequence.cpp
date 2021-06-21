// In this problem you have to find longest subsequence in a string which repeats itself in the stirng with other
// unique indexes means the two subsequences must contain different repeating character or you can say that one
// character will be part of only one repeating subsequence

// It is equivalent to finding the lcs on the string and another copy of the same string but don't count that
// in the LCS which has the same index

#include <bits/stdc++.h>
using namespace std;

int lcs_td(string& s1, string& s2, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) // Initialization of base case (represents the state when the length of any of the string is 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1] && i != j) // Represents the state when the last character is matching
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else // Represents the state when the last character is not matching
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main()
{
    string s;
    cout << "Enter the string : ";
    cin >> s;
    cout << "Length of the longest repeating subsequence : ";
    cout << lcs_td(s, s, s.length(), s.length()) << "\n";
    return 0;
}