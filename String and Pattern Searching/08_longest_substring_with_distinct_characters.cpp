//Longest substring with distinct characters
//Time Complexity = O(n)

#include <bits/stdc++.h>
using namespace std;

int longestDist(string s)
{
    int n = s.length(), res = 0;
    vector<int> prev(256, -1);
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        i = max(i, prev[s[j]] + 1);
        int maxEnd = j - i + 1;
        res = max(res, maxEnd);
        prev[s[j]] = j;
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << longestDist(s);
    return 0;
}
