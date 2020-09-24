#include <iostream>
#include <algorithm>
using namespace std;

//Hoare partition
//Pivot is always first element
//Hoare is better than Lomuto
//But in terms of stability naive partition is better than both
//because both Hoare and Lomuto are unstable while naive partition is stable

//Both Lomuto & Hoare partitions are in place but Naive partition uses auxiliary space

//Lomuto returns the exact index of the particular pivot
//But it is not so in the Hoare's case
//In this case , Lomuto has an edge over Hoare partition
int partition(int *arr, int l, int h)
{
    int pivot = arr[l];
    int i = l - 1, j = h + 1;
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

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int pivot_index = partition(arr, 0, n - 1);
    for (int i : arr)
        cout << i << " ";
    cout << "\nPivot_index is :" << pivot_index;
    return 0;
}
