#include<bits/stdc++.h>
using namespace std;

// int edit_dist(string& s1, string& s2, int m, int n)
// {
//     if (m == 0 || n == 0)
//         return abs(m - n);  // these many insertions or deletions will be required when one of the string becomes empty

//     if (s1[m - 1] == s2[n - 1])
//         return edit_dist(s1, s2, m - 1, n - 1); // if last character is matching, we simply make a recursive call for m-1, n-1
//     else    // it is to check for 3 conditions of replacing , deleting and inserting a character respectively
//         return 1 + min({edit_dist(s1, s2, m - 1, n - 1), edit_dist(s1, s2, m - 1, n), edit_dist(s1, s2, m, n - 1) });
// }

int edit_dist(string& s1, string& s2, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = abs(i - j);
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
        }
    }
    return dp[m][n];
}

int main()
{
    string s1, s2;
    cout << "Enter first string :";
    cin >> s1;
    cout << "Enter second string :";
    cin >> s2;

    cout << edit_dist(s1, s2, s1.length(), s2.length()) << "\n";
    return 0;
}