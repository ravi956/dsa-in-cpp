// You are given two strings a and b and you have to give the minimum no. of insertions and deletions required in
// the string a to convert it to string b

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
    cout << "Enter the first string (string to be converted) : ";
    cin >> s1;
    cout << "Enter the second string : ";
    cin >> s2;
    int lcs_len = lcs_bu(s1, s2, s1.length(), s2.length());
    cout << "Min no. of insertions : " << s2.length() - lcs_len << "\n";
    cout << "Max no. of deletions : " << s1.length() - lcs_len << "\n";
    return 0;
}