#include <bits/stdc++.h>
using namespace std;

// Time Complexity = theta(n*k)
// Space Complexity = theta(n)
void k_closest_naive(int arr[], int n, int k, int x)
{
    bool visited[n] = {false};

    for (int i = 0; i < k; i++)
    {
        int min_diff = INT_MAX;
        int min_diff_idx;

        for (int j = 0; j < n; j++)
        {
            if (visited[j] == false && abs(arr[j] - x) <= min_diff)
            {
                min_diff = abs(arr[j] - x);
                min_diff_idx = j;
            }
        }
        cout << arr[min_diff_idx] << " ";
        visited[min_diff_idx] = true;
    }
}

// Time Complexity = O(n * log(k))
void k_closest_efficient(int arr[], int n, int k, int x)
{
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < k; i++)
        pq.push({abs(arr[i] - x), i});

    for (int i = k; i < n; i++)
    {
        int diff = abs(arr[i] - x);
        if (pq.top().first > diff)
        {
            pq.pop();
            pq.push({diff, i});
        }
    }

    for (int i = 0; i < k; i++)
    {
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int x, k;
    cin >> x >> k;

    k_closest_naive(arr, n, k, x);
    cout << endl;
    k_closest_efficient(arr, n, k, x);
    return 0;
}