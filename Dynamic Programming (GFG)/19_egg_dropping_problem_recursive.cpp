// Problem : https://leetcode.com/problems/super-egg-drop/

#include<bits/stdc++.h>
using namespace std;

int eggDrop_rec(int e, int f)
{
    if (f == 0 || f == 1)
        return f;

    if (e == 1)
        return f;

    int min_attempt = INT_MAX;

    for (int k = 1; k <= f; k++)
    {
        int temp = 1 + max(eggDrop_rec(e - 1, k - 1), eggDrop_rec(e, f - k));
        if (temp < min_attempt)
            min_attempt = temp;
    }

    return min_attempt;
}

int main()
{
    int e, f;
    cout << "Enter no. of eggs : ";
    cin >> e;
    cout << "Enter no. of floors in building : ";
    cin >> f;

    cout << "Minimum no. of attempts required : " << eggDrop_rec(e, f) << "\n";
    return 0;
}