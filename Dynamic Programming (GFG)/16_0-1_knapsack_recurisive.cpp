#include<bits/stdc++.h>
using namespace std;

int knapSack(int* val, int* wt, int W, int n)
{
	if (n == 0 || W == 0)
		return 0;

	if (wt[n - 1] <= W)
		return max(val[n - 1] + knapSack(val, wt, W - wt[n - 1], n - 1), knapSack(val, wt, W, n - 1));
	else
		return knapSack(val, wt, W, n - 1);
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