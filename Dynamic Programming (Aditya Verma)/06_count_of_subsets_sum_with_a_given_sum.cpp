// In this problem, you have to find out the total no. of subsets in the array whose sum is equal to the given target sum

#include <bits/stdc++.h>
using namespace std;

int countSubsetSum(int arr[], int sum, int n)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++) //Initialization
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main()
{
    int n, sum;
    cout << "Enter no. of elements in the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array :\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter target sum : ";
    cin >> sum;
    cout << "Count : ";
    cout << countSubsetSum(arr, sum, n);
    return 0;
}