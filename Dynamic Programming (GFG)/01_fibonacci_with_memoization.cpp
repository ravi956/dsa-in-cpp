#include<bits/stdc++.h>
using namespace std;

int memo[1000];

int fibo(int n)
{
    if (memo[n] == -1)
    {
        int res;
        if (n == 0 || n == 1)
            res = n;
        else
            res = fibo(n - 1) + fibo(n - 2);

        memo[n] = res;
    }
    return memo[n];
}

int main()
{
    int n;
    cin >> n;

    memset(memo, -1, sizeof(memo));
    cout << fibo(n) << "\n";
    return 0;
}