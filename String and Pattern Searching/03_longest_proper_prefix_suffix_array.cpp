//Rabin Karp Pattern Searching Algorithm
//Time Complexity =  O((m+n-1)*m) =>Quadratic for worst case , for cases like[txt="aaaaaa" & pat="aaa"]
//Time Complexity =  O(n) =>Linear for average case

//Advantage of this algorithm is that it can be used to search multiple patterns at a time

#include <bits/stdc++.h>
using namespace std;

void RBsearch(string &txt, string &pat)
{
    int n = txt.length();
    int m = pat.length();
    int h = 1, d = 26, q = 29;       //d should be equal to total no. of possible distinct characters int the string
    for (int i = 1; i <= m - 1; i++) //q should be a prime no. as much greater as possible to avoid spursion hits
        h = (h * d) % q;
    int p = 0, t = 0;
    for (int i = 0; i < m; i++)
    {
        p = ((p * d) + pat[i]) % q;
        t = ((t * d) + txt[i]) % q;
    }
    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
                if (pat[j] != txt[j + i])
                {
                    flag = false;
                    break;
                }
            if (flag == true)
                cout << i << " ";
        }
        if (i < n - m)
        {
            t = (d * (t - (h * txt[i])) + txt[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }
}

int main()
{
    string s, p;
    cin >> s;
    cin >> p;
    RBsearch(s, p);
    return 0;
}
