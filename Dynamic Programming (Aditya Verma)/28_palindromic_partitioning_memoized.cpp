#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

bool isPalindrome(string& str, int i, int j)
{
    while (i < j)
    {
        if (str[i++] != str[j--])
            return false;
    }
    return true;
}

int mcm_mem(string& str, int i, int j)
{
    if (i >= j || isPalindrome(str, i, j))
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        ans = min(ans, mcm_mem(str, i, k) + mcm_mem(str, k + 1, j) + 1);
    }
    return dp[i][j] = ans;
}

int main()
{
    string str;
    cin >> str;

    memset(dp, -1, sizeof(dp));

    int ans = mcm_mem(str, 0, str.length() - 1);
    cout << ans << "\n";
    return 0;
}