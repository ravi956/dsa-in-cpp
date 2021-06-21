// To find the minimum no. of deletions required to make a given string a palindrome by doing minimum deletions in the string

// Min Deletions = Min Insertions = str.length() - LCS(str, reverse(str)) = str.length() - LPS
// If a question is asked to get the minimum no. of insertions to make a string palindrome , it will be equal to 
// minimum no. of deletions to make a string palindrome because the characters which are not the part of the 
// palindrome which are going to be deleted in order to make the string palindrome can also be inserted in order
// to make the string palindrome
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
    cout << "Min no of deletions to make a string a palindrome : ";
    cout << s1.length() - lcs_td(s1, s2, s1.length(), s2.length()) << "\n";
    return 0;
}