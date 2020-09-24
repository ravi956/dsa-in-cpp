#include <iostream>
using namespace std;

void print(int *arr[], int n, int m)
{
    int top = 0, right = m - 1, bottom = n - 1, left = 0;
    while (top <= bottom && left <= right)
    {
        if (top == bottom)
        {
            for (int i = top, j = left; j <= right; j++)
                cout << arr[i][j] << " ";
        }
        else if (left == right)
        {
            for (int j = left, i = top; i <= bottom; i++)
                cout << arr[i][j] << " ";
        }
        else
        {
            for (int i = top, j = left; j <= right - 1; j++)
                cout << arr[i][j] << " ";
            for (int j = right, i = top; i <= bottom - 1; i++)
                cout << arr[i][j] << " ";
            for (int i = bottom, j = right; j >= left + 1; j--)
                cout << arr[i][j] << " ";
            for (int j = left, i = bottom; i >= top + 1; i--)
                cout << arr[i][j] << " ";
        }
        top++;
        right--;
        bottom--;
        left++;
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
