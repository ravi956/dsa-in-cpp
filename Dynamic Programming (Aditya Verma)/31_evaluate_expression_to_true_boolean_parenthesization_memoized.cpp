// In this problem, you are give a string consisting of {'T'(true), 'F'(false), '|'(or), '&'(and), '^'(xor)} , you have to find
// out the total no. of ways to do the parenthesization of the string in order to evaluate the string to be TRUE as a boolean expression

// For this problem, memoization can be done by using 3-D matrix or map (because threee variables changing during the recursive function calls)
// Try to use 3-D matrix (I realised that it is faster as compared to map approach because the map approach is giving TLE on GFG but 
// 3-D matrix approach to memoize passes all the test cases within 1 sec)

#include<bits/stdc++.h>
using namespace std;

// unordered_map<string, int> dp;
int dp[201][201][2];

int mcm_rec(string& str, int i, int j, bool isTrue)
{
    if (i > j)
        return 0;
    if (i == j)
        return (isTrue) ? str[i] == 'T' : str[i] == 'F';

    // string key = to_string(i);
    // key.push_back(' ');
    // key.append(to_string(j));
    // key.push_back(' ');
    // isTrue ? key.push_back('T') : key.push_back('F');

    // if (dp.find(key) != dp.end())
    //     return dp[key];

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

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
    // return dp[key] = ans;
    return dp[i][j][isTrue] = ans;
}

int main()
{
    string str;
    cin >> str;

    memset(dp, -1, sizeof(dp));

    cout << mcm_rec(str, 0, str.length() - 1, true) << "\n";
    return 0;
}