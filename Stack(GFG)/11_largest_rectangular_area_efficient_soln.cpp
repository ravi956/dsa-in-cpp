//Efficient Solution
//Time complexity = O(n) Space Complexity = O(n)
//It requires only one traversal of the array and one auxiliary stack
#include <bits/stdc++.h>
using namespace std;

int largestArea(int arr[], int n)
{
    stack<int> s;
    int tp;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] >= arr[i])
        {
            tp = s.top();
            s.pop();
            int curr = arr[tp] * (s.empty() ? i : (i - s.top() - 1));
            res = max(res, curr);
        }
        s.push(i);
    }

    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        int curr = arr[tp] * (s.empty() ? n : (n - s.top() - 1));
        res = max(res, curr);
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter no. of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements :\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Largest Area : ";
    cout << largestArea(arr, n);
    return 0;
}