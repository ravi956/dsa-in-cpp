// Problem Link : https://www.geeksforgeeks.org/dynamic-programming-building-bridges/
#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(n*log(n))

int max_bridges(vector<pair<int, int>>& v)
{
    sort(v.begin(), v.end()); // Time complexity => O(n*log(n))

    vector<int> tail;
    tail.push_back(v[0].second);

    for (int i = 1; i < v.size(); i++)  // Time complexity => O(n*log(n))
    {
        if (v[i].second > tail.back())
            tail.push_back(v[i].second);
        else
        {
            int ceil_idx = upper_bound(tail.begin(), tail.end(), v[i].second) - tail.begin();
            tail[ceil_idx] = v[i].second;
        }
    }

    return tail.size();
}

int main()
{
    int n;
    cout << "Enter no. of bridges : ";
    cin >> n;

    vector<pair<int, int>> v(n);
    cout << "Enter bridges : \n";

    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    cout << max_bridges(v) << "\n";
    return 0;
}