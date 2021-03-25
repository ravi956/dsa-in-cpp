#include <bits/stdc++.h>
using namespace std;

struct item
{
    int wt, val;
    double valByWt;

    bool operator<(item i) const
    {
        return this->valByWt > i.valByWt;
    }
};

// Time Complexity => O(n*log(n))
int max_value(item it[], int n, int cap)
{
    sort(it, it + n);

    int result = 0;

    for (int i = 0; i < n; i++)
    {
        int min_wt = min(cap, it[i].wt);
        int value = it[i].valByWt * min_wt;

        result += value;
        cap -= min_wt;

        if (cap == 0)
            break;
    }

    return result;
}

int main()
{
    int n;
    cout << "Enter no. of items : ";
    cin >> n;

    item it[n];
    cout << "Enter item's weight and value :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> it[i].wt >> it[i].val;
        it[i].valByWt = (double)it[i].val / it[i].wt;
    }

    cout << "Enter capacity : ";
    int capacity;
    cin >> capacity;

    cout << "Maximum Value : " << max_value(it, n, capacity);
}