
/****************************************************************************************************************************
Medium Question on LeetCode -> Kth symbol grammar

On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0
with 01, and each occurrence of 1 with 10.

Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).

Examples:
Input: N = 1, K = 1
Output: 0

Input: N = 2, K = 1
Output: 0

Input: N = 2, K = 2
Output: 1

Input: N = 4, K = 5
Output: 1

Explanation:
row 1: 0
row 2: 01
row 3: 0110
row 4: 01101001

Note:
1. N will be an integer in the range [1, 30].
2. K will be an integer in the range [1, 2^(N-1)].
****************************************************************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int solve(int n, int k)            //Hypothesis that it will give the output for (n,k)
{
    if (n==1 && k==1)              //Base Case
        return 0;
    int mid = pow(2, n-1)/2;
    if (k<=mid)                    //Induction
        return solve(n-1, k);
    else                           //Induction
        return !solve(n-1, k-mid);
}

int main()
{
    int n, k;
    cin>>n>>k;
    cout<<solve(n, k);             //Recursive function which returns the required output
    return 0;
}