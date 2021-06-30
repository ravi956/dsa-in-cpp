// Problem : In this problem you have to find the minimum no. of deletions required to make an array sorted in
// increasing order
// Solution : min_deletions = length of array (n) - length of LIS

#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int>& v)
{
    vector<int> tail;
    tail.push_back(v[0]);

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > tail.back())
            tail.push_back(v[i]);
        else
        {
            int ceil_idx = upper_bound(tail.begin(), tail.end(), v[i]) - tail.begin();
            tail[ceil_idx] = v[i];
        }
    }
    return tail.size();
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << n - LIS(v) << '\n';
    return 0;
}