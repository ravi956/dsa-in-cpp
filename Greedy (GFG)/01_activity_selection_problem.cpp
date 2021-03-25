#include <bits/stdc++.h>
using namespace std;

bool myComp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

// Time Complexity => O(n*log(n))
int max_activity(vector<pair<int, int>> &act)
{
    sort(act.begin(), act.end(), &myComp);

    int result = 1;
    int last_end = act[0].second;

    for (int i = 1; i < act.size(); i++)
    {
        if (last_end <= act[i].first)
        {
            result++;
            last_end = act[i].second;
        }
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter no. of activities : ";
    cin >> n;

    vector<pair<int, int>> act;
    cout << "Enter activities start time & end time : \n";

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        act.push_back({start, end});
    }

    cout << "max_acitivity = " << max_activity(act);
    return 0;
}
