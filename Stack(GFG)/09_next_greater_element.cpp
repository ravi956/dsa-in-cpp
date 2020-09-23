#include <bits/stdc++.h>
using namespace std;

vector<int> printNextGreater(int arr[], int n)
{
    vector<int> v;
    stack<int> s;
    v.push_back(-1);
    s.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        while (s.empty() == false && s.top() <= arr[i])
            s.pop();

        int nextGreater = s.empty() ? -1 : s.top();
        v.push_back(nextGreater);
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
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
    vector<int> result = printNextGreater(arr, n);
    cout << "Next Greater Elements are :\n";
    for (int val : result)
        cout << val << " ";
    return 0;
}