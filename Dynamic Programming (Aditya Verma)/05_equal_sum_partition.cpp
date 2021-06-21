// In this problem, you have to find that if it is possible to divide whole array in two subsets such that their 
// sum is equal.

#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int sum, int n)
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++) //Initialization
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

bool equalSum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return false;
    else
        return subsetSum(arr, sum / 2, n);
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
    if (equalSum(arr, n))
        cout << "True";
    else
        cout << "False";
    return 0;
}