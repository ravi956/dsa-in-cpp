#include <iostream>
#include <algorithm>
using namespace std;

//Lomuto partition
//Pivot is always last element
//If you want to partition the array using other index then simply swap
//that pivot with last element in order to make last element pivot
//and then apply standard Lomuto Partion
int partition(int *arr, int l, int high) //add p_index as an argument
{
    //swap(arr[p_index],arr[high])
    int i = -1;
    int pivot = arr[high];
    for (int j = 0; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    //int p_index;
    //cin>>p_index;
    int pivot_index = partition(arr, 0, n - 1); //add p_index as an argument
    for (int i : arr)
        cout << i << " ";
    cout << "\nPivot_index is :" << pivot_index;
    return 0;
}
