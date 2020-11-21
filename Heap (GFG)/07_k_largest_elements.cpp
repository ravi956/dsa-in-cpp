#include <bits/stdc++.h>
using namespace std;

// Time Complexity = O(n*log(n))
void method1(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int i = n - 1;
    while (k--)
    {
        cout << arr[i--] << " ";
    }
}

// Time Complexity = O(n + k*log(n))
void method2(int arr[], int n, int k)
{
    priority_queue<int> maxHeap(arr, arr + n);

    while (k--)
    {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
}

// Time Complexity = O(k + (n-k)*log(k))
void method3(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<>> minHeap;
    for (int i = 0; i < k; i++)
    {
        minHeap.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (minHeap.top() > arr[i])
            continue;
        else
        {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

    while (minHeap.empty() == false)
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;

    // method1(arr, n, k);
    // method2(arr, n, k);
    method3(arr, n, k);
    return 0;
}