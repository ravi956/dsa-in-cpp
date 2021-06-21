// In this problem, you have to divide the array in two subsets such that the absolute difference bw their sums
// is minimum.

#include <bits/stdc++.h>
using namespace std;

vector<int> subsetSum(int arr[], int sum, int n)
{
    vector<int> lastRow;
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

    for (int i = n, j = 0; j <= sum / 2; j++)
    {
        if (dp[i][j] == true)
            lastRow.push_back(j);
    }
    return lastRow;
}

int minSubsetSumDiff(int arr[], int n)
{
    int range = 0;
    for (int i = 0; i < n; i++)
        range += arr[i];
    vector<int> candidate = subsetSum(arr, range, n);

    int mn = INT_MAX;
    for (int i = 0; i < candidate.size(); i++)
    {
        mn = min(mn, range - (2 * candidate[i]));
    }
    return mn;
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
    cout << "Minimum Subset Sum Difference : ";
    cout << minSubsetSumDiff(arr, n);
    return 0;
}