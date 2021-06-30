#include<bits/stdc++.h>
using namespace std;

int knapSack(int* val, int* wt, int W, int n)
{
	int dp[n + 1][W + 1];

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (wt[i - 1] <= j)
				dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][W];
}

int main()
{
	int n;
	cin >> n;

	int val[n], wt[n];

	for (int i = 0; i < n; i++)
		cin >> val[i];

	for (int i = 0; i < n; i++)
		cin >> wt[i];

	int W;
	cin >> W;

	cout << knapSack(val, wt, W, n) << "\n";
	return 0;
}