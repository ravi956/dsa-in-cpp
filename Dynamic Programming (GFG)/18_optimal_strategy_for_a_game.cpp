// Problem : In this problem, there are two players in this game, an array of coins is given
// to you , on each turn a player can choose one coin from the ends either from left or right
// Both players play optimally in order to maximize their coins, if you are the first player
// then find out the maximum value you can get by playing optimally.

#include<bits/stdc++.h>
using namespace std;

// int maxValue(int* arr, int l, int r)
// {
// 	if (l + 1 == r)
// 		return max(arr[l], arr[r]);

// 	return max(arr[l] + min(maxValue(arr, l + 2, r), maxValue(arr, l + 1, r - 1)),
// 	           arr[r] + min(maxValue(arr, l + 1, r - 1), maxValue(arr, l, r - 2)));
// }

// Time Complexity => theta(n*n)
// Space Complexity => theta(n*n)

int maxValue(int* arr, int n)
{
	int dp[n][n];

	for (int i = 0; i < n - 1; i++)
		dp[i][i + 1] = max(arr[i], arr[i + 1]);

	int col_start = 3;
	while (col_start < n)
	{
		int i = 0, j = col_start;
		while (i < n && j < n)
		{
			dp[i][j] = max(arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
			               arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));

			i++, j++;
		}
		col_start += 2;
	}
	return dp[0][n - 1];
	// If you don't want to fill the table like above cause its complicated
	// you can use memoization
}

int main()
{
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// cout << maxValue(arr, 0, n - 1) << "\n";
	cout << maxValue(arr, n) << "\n";
	return 0;
}