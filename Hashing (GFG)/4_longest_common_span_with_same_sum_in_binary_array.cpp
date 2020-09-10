#include <bits/stdc++.h>
using namespace std;

int solve(int arr1[], int arr2[], int n)
{
    unordered_map<int, int> m;
    int res = 0;
    int p_sum1 = 0;
    int p_sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        p_sum1 += arr1[i];
        p_sum2 += arr2[i];
        if (m.find(p_sum1 - p_sum2) != m.end())
            res = max(res, i - m[p_sum1 - p_sum2]);
        else
            m[p_sum1 - p_sum2] = i;
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter no. of elements in array : ";
    cin >> n;
    int arr1[n];
    int arr2[n];
    cout << "Enter elements of first binary array :\n";
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    cout << "Enter elements of second binary array :\n";
    for (int i = 0; i < n; i++)
        cin >> arr2[i];
    cout << solve(arr1, arr2, n);
    return 0;
}

/*
Method : 2 ------------------------------------------------------------------->
//C++ program to find largest subarray 
// with equal number of 0's and 1's. 
#include <bits/stdc++.h> 
using namespace std; 

// Returns largest common subarray with equal 
// number of 0s and 1s in both of the array 
int longestCommonSum(bool arr1[], bool arr2[], int n) 
{ 
	// Find difference between the two 
	int arr[n]; 
	for (int i=0; i<n; i++) 
	arr[i] = arr1[i] - arr2[i]; 
	
	// Creates an empty hashMap hM 
	unordered_map<int, int> hM; 

	int sum = 0;	 // Initialize sum of elements 
	int max_len = 0; // Initialize result 

	// Traverse through the given array 
	for (int i = 0; i < n; i++) 
	{ 
		// Add current element to sum 
		sum += arr[i]; 

		// To handle sum=0 at last index 
		if (sum == 0) 
			max_len = i + 1; 

		// If this sum is seen before, 
		// then update max_len if required 
		if (hM.find(sum) != hM.end()) 
		max_len = max(max_len, i - hM[sum]); 
			
		else // Else put this sum in hash table 
			hM[sum] = i; 
	} 

	return max_len; 
} 

// Driver progra+m to test above function 
int main() 
{ 
	bool arr1[] = {0, 1, 0, 1, 1, 1, 1}; 
	bool arr2[] = {1, 1, 1, 1, 1, 0, 1}; 
	int n = sizeof(arr1)/sizeof(arr1[0]); 
	cout << longestCommonSum(arr1, arr2, n); 
	return 0; 
} 

*/