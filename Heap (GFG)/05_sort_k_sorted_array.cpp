#include <bits/stdc++.h>
using namespace std;

// Time Complexity = O((n+k)log(k))
void sort(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i <= k; i++)
        pq.push(arr[i]);

    int index = 0;

    for (int i = k + 1; i < n; i++)
    {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while (pq.empty() == false)
    {
        arr[index++] = pq.top();
        pq.pop();
    }
}

int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the values : " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    sort(arr, n, k);
    cout << "Sorted Array : \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}