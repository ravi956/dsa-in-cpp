// In this problem you are given a string and you have to do the minimum partition of the string such that every
// partition is palindrome
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string& str, int i, int j)
{
    while (i < j)
    {
        if (str[i++] != str[j--])
            return false;
    }
    return true;
}

int mcm_rec(string& str, int i, int j)
{
    if (i >= j || isPalindrome(str, i, j))
        return 0;

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        ans = min(ans, mcm_rec(str, i, k) + mcm_rec(str, k + 1, j) + 1);
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;

    int ans = mcm_rec(str, 0, str.length() - 1);
    cout << ans << "\n";
    return 0;
}