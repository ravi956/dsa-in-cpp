#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n)
{
    int res = 0;
    unordered_set<int> us;
    for (int i = 0; i < n; i++)
        us.insert(arr[i]);
    for (int i = 0; i < n; i++)
    {
        if (us.find(arr[i] - 1) == us.end())
        {
            int curr = 1;
            while (us.find(arr[i] + curr) != us.end())
            {
                curr++;
            }
            res = max(res, curr);
        }
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter no. of elements in array : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements :\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << solve(arr, n);
    return 0;
}