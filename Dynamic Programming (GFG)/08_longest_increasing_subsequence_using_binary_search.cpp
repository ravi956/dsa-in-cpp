#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(n*log(n))
// Space Complexity => O(n)

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

    cout << LIS(v) << '\n';
    return 0;
}