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
        int left = (dp[i][k] != -1) ? dp[i][k] : mcm_mem(str, i, k);
        int right = (dp[k + 1][j] != -1) ? dp[k + 1][j] : mcm_mem(str, k + 1, j);
        ans = min(ans, left + right + 1);
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