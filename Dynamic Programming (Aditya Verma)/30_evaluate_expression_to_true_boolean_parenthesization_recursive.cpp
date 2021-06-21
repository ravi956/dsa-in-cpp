// In this problem, you are give a string consisting of {'T'(true), 'F'(false), '|'(or), '&'(and), '^'(xor)} , you have to find
// out the total no. of ways to do the parenthesization of the string in order to evaluate the string to be TRUE as a boolean expression

#include<bits/stdc++.h>
using namespace std;

int mcm_rec(string& str, int i, int j, bool isTrue)
{
    if (i > j)
        return 0;
    if (i == j)
        return (isTrue) ? str[i] == 'T' : str[i] == 'F';

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lTrue = mcm_rec(str, i, k - 1, true);
        int lFalse = mcm_rec(str, i, k - 1, false);
        int rTrue = mcm_rec(str, k + 1, j, true);
        int rFalse = mcm_rec(str, k + 1, j, false);

        if (str[k] == '|')
        {
            if (isTrue)
                ans += (lTrue * rTrue + lTrue * rFalse + lFalse * rTrue);
            else
                ans += (lFalse * rFalse);
        }
        else if (str[k] == '&')
        {
            if (isTrue)
                ans += (lTrue * rTrue);
            else
                ans += (lFalse * rFalse + lTrue * rFalse + lFalse * rTrue);
        }
        else if (str[k] == '^')
        {
            if (isTrue)
                ans += (lTrue * rFalse + lFalse * rTrue);
            else
                ans += (lFalse * rFalse + lTrue * rTrue);
        }
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;

    cout << mcm_rec(str, 0, str.length() - 1, true) << "\n";
    return 0;
}