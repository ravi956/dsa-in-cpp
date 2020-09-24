#include <iostream>
#include <algorithm>
using namespace std;

void countSort(int arr[], int n, int k)
{
    int count[k] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i < n; i++)
        count[i] += count[i - 1];

    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main()
{
    int n, k;
    cout << "Enter no. of elements :";
    cin >> n;
    cout << "Enter the value of k i.e range of numbers :"; //k is the maximum value of arr[i]
    cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    countSort(arr, n, k);
    for (int num : arr)
        cout << num << " ";
    return 0;
}
