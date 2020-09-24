//KMP Pattern Searching Algorithm
//Time Complexity = O(n)
//Aux Space = O(m) [for lps array]

#include <bits/stdc++.h>
using namespace std;

void fillLps(string &s, vector<int> &lps)
{
    int n = s.length();
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < n)
    {
        if (s[len] == s[i])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
                len = lps[len - 1];
        }
    }
}

void kmpSearch(string &s, string &p)
{
    int n = s.length();
    int m = p.length();
    vector<int> lps(m);
    fillLps(p, lps);
    int i = 0, j = 0;
    while (i < n)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << i - j << " ";
            j = lps[j - 1];
        }
        else if (i < n && s[i] != p[j])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

int main()
{
    string s, p;
    cin >> s >> p;
    kmpSearch(s, p);
    return 0;
}
