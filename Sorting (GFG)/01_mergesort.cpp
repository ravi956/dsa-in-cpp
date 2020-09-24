#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int temp1[n1], temp2[n2];
    for (int i = 0; i < n1; i++)
        temp1[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        temp2[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (temp1[i] <= temp2[j])
            arr[k++] = temp1[i++];
        else
            arr[k++] = temp2[j++];
    }
    while (i < n1)
        arr[k++] = temp1[i++];
    while (j < n2)
        arr[k++] = temp2[j++];
}

void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int n;
    cout << "Enter the size of array :";
    cin >> n;
    int arr[n];
    cout << "Enter the elements :\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mergesort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}
