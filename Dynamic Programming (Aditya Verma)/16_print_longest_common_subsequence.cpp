// To print the lcs string not its length

#include <bits/stdc++.h>
using namespace std;

string lcs_bu(string& s1, string& s2, int m, int n)
{
    int dp[m + 1][n + 1];
    string lcs_string = "";

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

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs_string.push_back(s1[i - 1]);
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(lcs_string.begin(), lcs_string.end());

    return lcs_string;
}

int main()
{
    string s1, s2;
    cout << "Enter the first string : ";
    cin >> s1;
    cout << "Enter the second string : ";
    cin >> s2;
    cout << "Longest common subsequence : ";
    cout << lcs_bu(s1, s2, s1.length(), s2.length()) << "\n";
    return 0;
}