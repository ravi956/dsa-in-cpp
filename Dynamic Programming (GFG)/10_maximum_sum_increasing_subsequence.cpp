// Problem : In this problem you have to find the maximum sum of increasing subsequence of an array

#include<bits/stdc++.h>
using namespace std;

int MSIS(int* arr, int n)
{
    int msis[n];

    for (int i = 0; i < n; i++)
    {
        msis[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                msis[i] = max(msis[i], msis[j] + arr[i]);
        }
    }

    int res = *max_element(msis, msis + n);
    return res;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << MSIS(arr, n) << '\n';
    return 0;
}