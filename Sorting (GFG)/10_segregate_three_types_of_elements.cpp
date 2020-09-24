#include <bits/stdc++.h>
using namespace std;

//This can also be solved by using partition techniques of QuickSort algo i.e. Lomuto or Hoer partition
//This is a program to segregate three types of elements right now 0's , 1's and 2's

//Solution using Dutch National Flag Algo.
void solve(int arr[], int n)
{
    int low = 0, high = n - 1;
    int mid = 0;
    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[mid], arr[low]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[high]);
            high--;
            break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
