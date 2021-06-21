// In this problem, you have to calculate the minimum no. of multiplication operations to be done in order to 
// multiply a no. of matrices with given their dimensions (ROW X COL) by applying parenthesization to decide the
// order of multiplication of matrices

#include<bits/stdc++.h>
using namespace std;

int mcm_rec(int* arr, int i, int j)
{
    if (i == j)
        return 0;

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        ans = min(ans, mcm_rec(arr, i, k) + mcm_rec(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int arr[n]; // Dimension of the ith matrix is arr[i-1]xarr[i]
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = mcm_rec(arr, 1, n - 1);
    cout << ans << "\n";
    return 0;
}