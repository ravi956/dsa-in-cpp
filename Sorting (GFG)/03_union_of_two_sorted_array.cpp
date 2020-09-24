#include <iostream>
#include <algorithm>
using namespace std;

void union_func(int *a, int n1, int *b, int n2)
{
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            if ((a[i] != a[i - 1]) || (i == 0))
                cout << a[i] << " ";
            i++;
        }
        else if (b[j] < a[i])
        {
            if ((b[j] != b[j - 1]) || (j == 0))
                cout << b[j] << " ";
            j++;
        }
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
    while (i < n1)
    {
        if (a[i] != a[i - 1] && a[i] != b[j - 1])
            cout << a[i] << " ";
        i++;
    }
    while (j < n2)
    {
        if (b[j] != b[j - 1] && b[j] != a[i - 1])
            cout << b[j] << " ";
        j++;
    }
}

int main()
{
    int n1, n2;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];
    union_func(arr1, n1, arr2, n2);
    return 0;
}
