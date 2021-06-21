// In this problem, you are given two strings and you have to calculate the maximum length of the subsequence which is 
// common in both the strings

#include <bits/stdc++.h>
using namespace std;

int lcs_rec(string& s1, string& s2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;

    if (s1[m - 1] == s2[n - 1])
        return 1 + lcs_rec(s1, s2, m - 1, n - 1);
    else
        return max(lcs_rec(s1, s2, m - 1, n), lcs_rec(s1, s2, m, n - 1));
}

int main()
{
    string s1, s2;
    cout << "Enter the first string : ";
    cin >> s1;
    cout << "Enter the second string : ";
    cin >> s2;
    cout << "Length of the longest common subsequence : ";
    cout << lcs_rec(s1, s2, s1.length(), s2.length()) << "\n";
    return 0;
}