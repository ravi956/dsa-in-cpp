// Problem : In this problem, you have to find the maximum length of the bitonic subsequence of an array
// Bitonic sequence is a sequence in which elements are in ascending order and then in descending order

#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(n*n)
// We can optimize this solution to O(n*log(n)) using the binary search approach instead of DP

int MLBS(int* arr, int n)
{
    int lis[n]; // lis[i] -> length of longest increasing subsequence which has arr[i] as the last element
    int lds[n]; // lds[i] -> length of longest decreasing subsequence which has arr[i] as the first element
    lis[0] = 1;
    lds[n - 1] = 1;

    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        lds[i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
                lds[i] = max(lds[i], lds[j] + 1);
        }
    }

    int res = 1;
    for (int i = 0; i < n; i++)
        res = max(res, lis[i] + lds[i] - 1);
    return res;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << MLBS(arr, n) << '\n';
    return 0;
}