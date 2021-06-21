// In this problem, you are given an array of integers and a target value , you have to find out whether it is 
// possible to make a subset from the array such that the sum of elements of the subset is equal to the target value.

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
    if (subsetSum(arr, sum, n))
        cout << "True";
    else
        cout << "False";
    return 0;
}