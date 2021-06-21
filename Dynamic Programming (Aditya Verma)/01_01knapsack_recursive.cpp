// In this problem, you are given a knapsack with some capacity W, and a list of item with their weights and values
// You have to fill the knapsack with chosen items such that the total value of the items in the knapsack is maximum.

#include <bits/stdc++.h>
using namespace std;

int knapsackRec(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knapsackRec(wt, val, W - wt[n - 1], n - 1),
            knapsackRec(wt, val, W, n - 1));
    }
    else
    {
        return knapsackRec(wt, val, W, n - 1);
    }
}

int main()
{
    int n, W;
    cout << "Enter no. of item (n) : ";
    cin >> n;
    int val[n], wt[n];
    cout << "Enter values of the items :\n";
    for (int i = 0; i < n; i++)
        cin >> val[i];
    cout << "Enter weights of the items :\n";
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    cout << "Enter capacity of the knapsack : ";
    cin >> W;
    cout << "Maximum Profit : ";
    cout << knapsackRec(wt, val, W, n);
    return 0;
}