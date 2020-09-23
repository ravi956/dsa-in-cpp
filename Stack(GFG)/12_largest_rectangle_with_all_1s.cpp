#include <bits/stdc++.h>
using namespace std;

int largestHist(int arr[], int n)
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

int maxRectangle(int *mat[], int r, int c)
{
    int result = largestHist(mat[0], c);
    for (int i = 1; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] != 0)
                mat[i][j] += mat[i - 1][j];
        }
        result = max(result, largestHist(mat[i], c));
    }
    return result;
}

int main()
{
    int r, c;
    cout << "Enter no. of rows and colums in the matrix : ";
    cin >> r >> c;
    int *mat[r];
    for (int i = 0; i < r; i++)
    {
        mat[i] = new int[c];
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];
    }
    cout << "Area of largest rectangle is " << maxRectangle(mat, r, c);
    return 0;
}