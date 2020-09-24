#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < arr[i].size(); j++)
                cout << arr[i][j] << " ";
        }
        else
        {
            for (int j = arr[i].size() - 1; j >= 0; j--)
                cout << arr[i][j] << " ";
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            arr[i].push_back(temp);
        }
    }
    print(arr, n);
    return 0;
}
