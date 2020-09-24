#include <iostream>
#include <algorithm>
using namespace std;

void intersect(int *arr1, int n1, int *arr2, int n2)
{
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (i != 0 && j != 0 && arr1[i] == arr1[i - 1] && arr2[j] == arr2[j - 1])
        {
            i++;
            j++;
        }
        else if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else
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
    intersect(arr1, n1, arr2, n2);
    return 0;
}
