#include <iostream>
using namespace std;

void print(int *arr[], int n, int m)
{
    if (n == 1)
    {
        for (int i = 0, j = 0; j < m; j++)
            cout << arr[i][j] << " ";
    }
    else if (m == 1)
    {
        for (int j = 0, i = 0; i < n; i++)
            cout << arr[i][j] << " ";
    }
    else
    {
        for (int i = 0, j = 0; j <= m - 2; j++)
            cout << arr[i][j] << " ";
        for (int j = m - 1, i = 0; i <= n - 2; i++)
            cout << arr[i][j] << " ";
        for (int i = n - 1, j = m - 1; j >= 1; j--)
            cout << arr[i][j] << " ";
        for (int j = 0, i = n - 1; i >= 1; i--)
            cout << arr[i][j] << " ";
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int *arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    print(arr, n, m);
    return 0;
}
