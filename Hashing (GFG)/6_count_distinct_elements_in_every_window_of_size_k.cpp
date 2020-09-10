#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++)
        mp[arr[i]]++;
    cout << mp.size() << " ";
    for (int i = k; i < n; i++)
    {
        mp[arr[i - k]]--;
        if (mp[arr[i - k]] == 0)
            mp.erase(arr[i - k]);
        mp[arr[i]]++;
        cout << mp.size() << " ";
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    solve(arr, n, k);
    return 0;
}