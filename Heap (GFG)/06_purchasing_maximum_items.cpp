#include <bits/stdc++.h>
using namespace std;

// Time Complexity = O(n*log(n))
int method1(int arr[], int n, int sum)
{
    sort(arr, arr + n);
    int res = 0;
    int i = 0;

    while (arr[i] <= sum)
    {
        sum -= arr[i];
        res++;
        i++;
    }
    return res;
}

// Time Complexity = O(res*log(n))
int method2(int arr[], int n, int sum)
{
    priority_queue<int, vector<int>, greater<>> pq(arr, arr + n);
    int res = 0;

    while (pq.top() <= sum)
    {
        sum -= pq.top();
        pq.pop();
        res++;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum;
    cin >> sum;

    // cout << method1(arr, n, sum) << endl;
    cout << method2(arr, n, sum) << endl;
    return 0;
}