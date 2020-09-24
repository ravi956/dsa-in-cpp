#include <iostream>
#include <algorithm>
using namespace std;

//quicksort using Hoare partition is on average 3 times faster as compared to Lomuto partition
//Considering Hoare's partition
int partition(int arr[], int l, int r)
{
    int pivot = arr[l];
    int i = l - 1, j = r + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p);
        quickSort(arr, p + 1, r);
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
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}
