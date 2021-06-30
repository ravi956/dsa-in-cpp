// Problem : Given an array, to find the count of the subsets of the array
// which sum to a target

#include<bits/stdc++.h>
using namespace std;

int countSubsets(int arr[], int n, int sum)
{
    if (n == 0)
        return sum == 0 ? 1 : 0;

    return countSubsets(arr, n - 1, sum) + countSubsets(arr, n - 1, sum - arr[n - 1]);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cin >> target;

    cout << countSubsets(arr, n, target) << "\n";
    return 0;
}