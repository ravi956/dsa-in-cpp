#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucketSort(int arr[], int n, int k)
{
    //Calculating the maximum value
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    //Incrementing the maximum value by 1
    maxVal++;

    //Putting the elements in the buckets to which they belong
    vector<int> bucket[k];
    for (int i = 0; i < n; i++)
    {
        int b_index = (k * arr[i]) / maxVal;
        bucket[b_index].push_back(arr[i]);
    }

    //Sorting each bucket
    for (int i = 0; i < k; i++)
        sort(bucket[i].begin(), bucket[i].end());

    //Placing the elements from the sorted bucket into the original array or concatination of sorted buckets
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[index++] = bucket[i][j];
        }
    }
}

int main()
{
    int n, k;
    cout << "Enter no. of elements in array :";
    cin >> n;
    cout << "Enter no. of buckets :";
    cin >> k;
    cout << "Now enter elements :\n";
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bucketSort(arr, n, k);
    for (int num : arr)
        cout << num << " ";
    return 0;
}
