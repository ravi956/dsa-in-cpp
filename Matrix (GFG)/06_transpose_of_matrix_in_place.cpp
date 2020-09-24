#include <iostream>
#include <algorithm>
using namespace std;

void print(int *arr[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void transpose(int *arr[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    cout << "transpose :\n";
    print(arr, n, m);
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
    transpose(arr, n, m);
    return 0;
}
