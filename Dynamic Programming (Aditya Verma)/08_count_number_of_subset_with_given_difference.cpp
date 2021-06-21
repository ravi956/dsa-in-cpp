//This problem is same as Target Sum problem of Leetcode (Q.494 Medium)

//In this problem, you have to find the total combinations of divisions of array into two subsets such that the 
//the difference bw their sums is equal to the given difference

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

int countSubsetWithDiff(int arr[], int diff, int n)
{
    int sumAll = 0;
    for (int i = 0; i < n; i++)
        sumAll += arr[i];

    int sum = (diff + sumAll) / 2;
    return countSubsetSum(arr, sum, n);
}

int main()
{
    int n, diff;
    cout << "Enter no. of elements in the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array :\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter diference : ";
    cin >> diff;
    cout << "Count : ";
    cout << countSubsetWithDiff(arr, diff, n);
    return 0;
}