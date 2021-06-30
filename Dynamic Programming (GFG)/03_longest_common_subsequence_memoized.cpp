#include<bits/stdc++.h>
using namespace std;

int memo[1001][1001];

int lcs(string& s1, string& s2, int l1, int l2)
{
    if (memo[l1][l2] != -1)
        return memo[l1][l2];
    else if (l1 == 0 || l2 == 0)
        memo[l1][l2] = 0;
    else if (s1[l1 - 1] == s2[l2 - 1])
        memo[l1][l2] = 1 + lcs(s1, s2, l1 - 1, l2 - 1);
    else
        memo[l1][l2] = max(lcs(s1, s2, l1 - 1, l2), lcs(s1, s2, l1, l2 - 1));
    return memo[l1][l2];
}

int main()
{
    string s1, s2;
    cout << "Enter first string : ";
    cin >> s1;
    cout << "Enter second string : ";
    cin >> s2;

    memset(memo, -1, sizeof(memo));

    cout << lcs(s1, s2, s1.length(), s2.length()) << "\n";
    return 0;
}