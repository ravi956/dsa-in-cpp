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

//rotate the matrix by 90 Deg anticlockwise
void rotate(int *arr[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (int j = 0; j < m; j++)
    {
        int low = 0, high = n - 1;
        while (low < high)
        {
            swap(arr[low][j], arr[high][j]);
            low++;
            high--;
        }
    }
    cout << "Rotation by 90Deg :\n";
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
    rotate(arr, n, m);
    return 0;
}
