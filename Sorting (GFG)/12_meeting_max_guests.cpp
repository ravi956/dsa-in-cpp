#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i = 1, j = 0;
    int res = 1, curr = 1;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            curr++;
            i++;
        }
        else
        {
            curr--;
            j++;
        }
        res = max(res, curr);
    }
    cout << "MaxGuest=" << res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n], dep[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i] >> dep[i];
    solve(arr, dep, n);
    return 0;
}
