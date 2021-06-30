// Problem : In this problem, you need to find the min jumps required to go from first cell to last cell and each cell has been
// assigned some value which is the max cell jumps can be made from that cell

#include<bits/stdc++.h>
using namespace std;

// int minJumpsRec(int* arr, int n)
// {
//     if (n == 1)
//         return 0;

//     int res = INT_MAX;
//     for (int i = 0; i <= n - 2; i++)
//     {
//         if (i + arr[i] >= n - 1)
//         {
//             int sub_res = minJumpsRec(arr, i + 1);
//             if (sub_res != INT_MAX)
//                 res = min(res, 1 + sub_res);
//         }
//     }
//     return res;
// }

int minJumps(int* arr, int n)
{
    int dp[n];
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (dp[j] != INT_MAX && j + arr[j] >= i)
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // cout << minJumpsRec(arr, n) << "\n";
    cout << minJumps(arr, n) << "\n";
    return 0;
}