#include <bits/stdc++.h>
using namespace std;

// Method1 => SuperNaive Solution
// Time complexity => O(nk*log(nk))
vector<int> method1(vector<vector<int>> &v)
{
    vector<int> res;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            res.push_back(v[i][j]);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

// Method2 => Naive Solution
vector<int> mergeArrays(vector<int> arr1, vector<int> arr2)
{
    int i = 0, j = 0;
    vector<int> res;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr2[j] < arr1[i])
            res.push_back(arr2[j++]);
        else
            res.push_back(arr1[i++]);
    }

    while (i < arr1.size())
    {
        res.push_back(arr1[i++]);
    }
    while (j < arr2.size())
    {
        res.push_back(arr2[j++]);
    }

    return res;
}

// Time Complexity => O(n*(k^2))
vector<int> method2(vector<vector<int>> &v)
{
    vector<int> res = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        res = mergeArrays(res, v[i]);
    }

    return res;
}

int main()
{
    vector<vector<int>> v;
    int k;
    cout << "Enter value of k : ";
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        vector<int> temp;
        int n;
        cout << "Enter the size of the array" << i + 1 << " : ";
        cin >> n;
        cout << "Enter values of array" << i + 1 << endl;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        v.push_back(temp);
    }

    vector<int> res = method2(v);
    cout << "\nMerged Array :\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}