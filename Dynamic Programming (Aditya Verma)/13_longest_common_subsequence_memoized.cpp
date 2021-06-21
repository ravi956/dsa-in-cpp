#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001]; //size depends on constraints, rows->length of s1, col-> length of s2

int lcs_mem(string &s1, string &s2, int m, int n)
{
    if (dp[m][n] != -1)
        return dp[m][n];

    if (m == 0 || n == 0)
        return 0;

    if (s1[m - 1] == s2[n - 1])
        return dp[m][n] = (1 + lcs_mem(s1, s2, m - 1, n - 1));
    else
        return dp[m][n] = max(lcs_mem(s1, s2, m - 1, n), lcs_mem(s1, s2, m, n - 1));
}

int main()
{
    memset(dp, -1, sizeof(dp)); // Initialization of dp matrix
    string s1, s2;
    cout << "Enter the first string : ";
    cin >> s1;
    cout << "Enter the second string : ";
    cin >> s2;
    cout << "Length of the longest common subsequence : ";
    cout << lcs_mem(s1, s2, s1.length(), s2.length()) << "\n";
    return 0;
}