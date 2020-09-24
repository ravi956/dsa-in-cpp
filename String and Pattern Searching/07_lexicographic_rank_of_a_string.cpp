//Lexicographic Rank of a string having distinct characters
//Time Complexity = O(n);
//Space Complexity = O(CHAR)

#include <bits/stdc++.h>
using namespace std;
#define CHAR 256

long long fact(long long n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}

long long lxRank(string &s)
{
    int n = s.length();
    long long rank = 0;
    long long x = fact(n);
    int count[CHAR] = {0};
    for (int i = 0; i < n; i++)
        count[s[i]]++;
    for (int i = 1; i < CHAR; i++)
        count[i] += count[i - 1];
    for (int i = 0; i < n - 1; i++)
    {
        x = (x / (n - i));
        rank += count[s[i] - 1] * x;
        for (int j = s[i]; j < CHAR; j++)
            count[j]--;
    }
    return rank + 1;
}

int main()
{
    string s;
    cin >> s;
    cout << lxRank(s) << endl;
    return 0;
}
