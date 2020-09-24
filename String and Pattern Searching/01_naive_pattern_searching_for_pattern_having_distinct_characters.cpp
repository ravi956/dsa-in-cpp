//Naive Pattern Searching Algorithm for distinct characters in the pattern string
//Time Complexity =  theta(n) =>Linear

#include <bits/stdc++.h>
using namespace std;

void search(string &s, string &p)
{
    int n = s.length();
    int m = p.length();
    for (int i = 0; i < n;)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (p[j] != s[j + i])
                break;
        }
        if (j == m)
            cout << i << " ";
        if (j == 0)
            i++;
        else
            i += j;
    }
}

int main()
{
    string s, p;
    cin >> s;
    cin >> p;
    search(s, p);
    return 0;
}
