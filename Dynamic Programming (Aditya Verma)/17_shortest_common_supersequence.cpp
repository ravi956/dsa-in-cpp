//In this problem, you are given two strings and you have to give the length of the string which is shortest supersequence for both strings
//which means the shortest string of which the given two strings are subsequences

//This problem can also be solved by calculating the value of (m + n - length of longest common subsequence) where m,n-> lengths of strings
#include <bits/stdc++.h>
using namespace std;

int scs_bu(string& s1, string& s2, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0) // Initialization of base case (represents the state when the length of any of the string is 0)
                dp[i][j] = 0;
            else if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1]) // Represents the state when the last character is matching
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else // Represents the state when the last character is not matching
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main()
{
    string s1, s2;
    cout << "Enter the first string : ";
    cin >> s1;
    cout << "Enter the second string : ";
    cin >> s2;
    cout << "Length of the shortest common supersequence : ";
    cout << scs_bu(s1, s2, s1.length(), s2.length()) << "\n";
    return 0;
}